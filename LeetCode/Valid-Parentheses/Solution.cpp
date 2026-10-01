1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char>st;
5        int open=0;
6        int close=0;
7        for(char c:s){
8            if(c=='('||c=='['||c=='{'){
9                st.push(c);
10                open++;
11            }
12            else{
13                if(st.size()&&st.top()=='('&&c==')') st.pop();
14                if(st.size()&&st.top()=='['&&c==']') st.pop();
15                if(st.size()&&st.top()=='{'&&c=='}') st.pop();
16                close++;
17            }
18        }
19        return (open==close)&&st.size()==0;
20    }
21};