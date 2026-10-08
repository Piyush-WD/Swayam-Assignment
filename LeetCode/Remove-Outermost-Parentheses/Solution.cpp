1class Solution {
2public:
3    string removeOuterParentheses(string s) {
4        int cnt=1;
5        string curr="(";
6        int n=s.size();
7        string ans;
8        for(int i=1;i<n;i++){
9            if(s[i]=='('){
10                cnt++;
11                curr+='(';
12            }
13            else{
14                curr+=')';
15                cnt--;
16                if(!cnt){
17                    curr.erase(0,1);
18                    curr.pop_back();
19                    ans=ans+curr;
20                    curr="";
21                }
22            }
23        }
24        return ans;
25    }
26};