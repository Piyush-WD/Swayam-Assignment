1class Solution {
2public:
3    unordered_map<int,vector<char>>map = {
4        {2, {'a','b','c'}},{3, {'d','e','f'}},{4, {'g','h','i'}},{5, {'j','k','l'}},{6, {'m','n','o'}},{7, {'p','q','r','s'}},{8, {'t','u','v'}},{9, {'w','x','y','z'}},
5    };
6
7    void solve(int i, vector<string>&ans, string curr, string &digits){
8        if(i==digits.size()){
9            ans.push_back(curr);
10            return;
11        }
12        for(char a:map[digits[i]-'0']){
13            curr.push_back(a);
14            solve(i+1,ans,curr,digits);
15            curr.pop_back();
16        }
17    }
18
19    vector<string> letterCombinations(string digits) {
20        if(digits.size()==0) return {};
21        string curr="";
22        vector<string>ans;
23        solve(0,ans,curr,digits);
24        return ans;
25    }
26};