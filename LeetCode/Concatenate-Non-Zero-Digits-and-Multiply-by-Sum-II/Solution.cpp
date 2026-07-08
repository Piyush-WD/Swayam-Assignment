1class Solution {
2public:
3    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
4        const long long MOD = 1000000007LL;
5        int n = s.size();
6
7        vector<long long> prefixConcat(n);
8        vector<int> prefixSum(n);
9        vector<int> cnt(n);
10        vector<long long> pow10(n + 1);
11
12        pow10[0] = 1;
13        for (int i = 1; i <= n; i++) {
14            pow10[i] = (pow10[i - 1] * 10) % MOD;
15        }
16
17        prefixSum[0] = s[0] - '0';
18        cnt[0] = (s[0] != '0');
19        prefixConcat[0] = (s[0] != '0') ? (s[0] - '0') : 0;
20
21        for (int i = 1; i < n; i++) {
22            prefixSum[i] = prefixSum[i - 1] + (s[i] - '0');
23            cnt[i] = cnt[i - 1];
24
25            if (s[i] != '0') {
26                cnt[i]++;
27                prefixConcat[i] =
28                    (prefixConcat[i - 1] * 10 + (s[i] - '0')) % MOD;
29            } else {
30                prefixConcat[i] = prefixConcat[i - 1];
31            }
32        }
33
34        vector<int> ans;
35
36        for (auto &q : queries) {
37            int l = q[0], r = q[1];
38
39            long long digitSum = prefixSum[r];
40            long long concat = prefixConcat[r];
41
42            if (l > 0) {
43                digitSum -= prefixSum[l - 1];
44
45                int k = cnt[r] - cnt[l - 1];
46                concat = (concat -
47                          (prefixConcat[l - 1] * pow10[k]) % MOD +
48                          MOD) % MOD;
49            }
50
51            ans.push_back((digitSum * concat) % MOD);
52        }
53
54        return ans;
55    }
56};