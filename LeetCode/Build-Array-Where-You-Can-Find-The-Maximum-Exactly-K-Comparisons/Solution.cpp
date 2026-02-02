1class Solution {
2public:
3    const int MOD = 1000000007;
4
5    int solve(vector<vector<vector<int>>>& dp, int i, int cost, int maxSoFar,
6              int n, int m, int k) {
7
8        if (cost > k) return 0;
9
10        if (i == n) {
11            return cost == k;
12        }
13
14        if (dp[i][cost][maxSoFar] != -1)
15            return dp[i][cost][maxSoFar];
16
17        long long result = 0;
18
19        for (int j = 1; j <= m; j++) {
20            if (j > maxSoFar)
21                result = (result + solve(dp, i+1, cost+1, j, n, m, k)) % MOD;
22            else
23                result = (result + solve(dp, i+1, cost, maxSoFar, n, m, k)) % MOD;
24        }
25
26        return dp[i][cost][maxSoFar] = result;
27    }
28
29    int numOfArrays(int n, int m, int k) {
30        vector<vector<vector<int>>> dp(
31            n, vector<vector<int>>(
32                k+1, vector<int>(m+1, -1)
33            )
34        );
35        return solve(dp, 0, 0, 0, n, m, k);
36    }
37};
38