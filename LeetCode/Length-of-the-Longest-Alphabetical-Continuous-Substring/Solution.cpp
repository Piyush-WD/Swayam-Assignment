1class Solution {
2public:
3    int longestContinuousSubstring(string s) {
4        if(s.size()<=1) return s.size();
5        int i=1;
6        int ans=1;
7        int n=s.size();
8        int cur=1;
9        while(i<n){
10            if((s[i]-'a')-(s[i-1]-'a')==1){
11                cur++;
12            }
13            else{
14                cur=1;
15            }
16            i++;
17            ans=max(ans,cur);
18        }
19        return ans;
20    }
21};