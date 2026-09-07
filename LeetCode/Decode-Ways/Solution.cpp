1class Solution {
2public:
3    int numDecodings(string s) {
4        if(s[0]=='0') return 0;
5        int n=s.size();
6        vector<int>dp(n+1,0);
7        dp[0]=dp[1]=1;
8        for(int i=2;i<=n;i++){
9            if(s[i-1]!='0') dp[i]+=dp[i-1];
10            int num=stoi(s.substr(i-2,2));
11            if(num>=10&&num<=26) dp[i]+=dp[i-2];
12        }
13        return dp[n];
14    }
15};