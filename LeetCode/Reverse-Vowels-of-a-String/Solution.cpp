1class Solution {
2public:
3    bool isVowel(char a){
4        return a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||
5        a=='U'||a=='O'||a=='I'||a=='E'||a=='A';
6    }
7
8    string reverseVowels(string s) {
9        stack<char>st;
10        for(char a:s){
11            if(isVowel(a)){
12                st.push(a);
13            }
14        }
15        for(int i=0;i<s.size();i++){
16            if(isVowel(s[i])){
17                s[i]=st.top();
18                st.pop();
19            }
20        }
21        return s;
22    }
23};