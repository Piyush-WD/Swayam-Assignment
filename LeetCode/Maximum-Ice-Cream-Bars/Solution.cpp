1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        int mx=*max_element(costs.begin(), costs.end());
5        vector<int>cnt(mx+1,0);
6        for(int i:costs){
7            cnt[i]++;
8        }
9        int idx=1;
10        int ans=0;
11        while(idx<=mx&&coins>=idx){
12            while(cnt[idx]&&coins-idx>=0){
13                ans++;
14                coins-=idx;
15                cnt[idx]--;
16            }
17            idx++;
18        }
19        return ans;
20    }
21};