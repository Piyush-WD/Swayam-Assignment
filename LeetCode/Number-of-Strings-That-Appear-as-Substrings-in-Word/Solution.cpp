1class Solution {
2public:
3    bool hasSubstr(string a, string b){
4        if(a.size()>b.size()) return 0;
5        else if(a.size()==b.size()) return a==b;
6        else{
7            for(int i=0;i<=b.size()-a.size();i++){
8                if(b.substr(i,a.size())==a) return 1;
9            }
10            return 0;
11        }
12    }
13
14    int numOfStrings(vector<string>& patterns, string word) {
15        int ans=0;
16        for(string i:patterns){
17            if(hasSubstr(i,word)) ans++;
18        }
19        return ans;
20    }
21};