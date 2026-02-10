1class Solution {
2public:
3    int solve(int i, int j, vector<vector<int>>&dp, int m, int n){
4        if(i==m-1&&j==n-1){
5            return 1;
6        }
7        if(i>=m||j>=n){
8            return 0;
9        }
10        if(dp[i][j]!=-1){
11            return dp[i][j];
12        }
13        int right = solve(i,j+1,dp,m,n);
14        int down = solve(i+1,j,dp,m,n);
15        return dp[i][j]=right+down;
16    }
17
18    int uniquePaths(int m, int n) {
19        vector<vector<int>>dp(m, vector<int>(n, -1));
20        return solve(0, 0, dp, m, n);
21    }
22};