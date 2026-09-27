1class Solution {
2public:
3    string reverseParentheses(string s) {
4        stack<int>st;
5        string ans;
6        for(char c:s){
7            if(c=='('){
8                st.push(ans.size());
9            }
10            else if(c==')'){
11                int start=st.top();
12                st.pop();
13                reverse(ans.begin()+start, ans.end());
14            }
15            else{
16                ans+=c;
17            }
18        }
19        return ans;
20    }
21};