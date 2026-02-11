1class Solution {
2public:
3    vector<vector<int>> generate(int numRows) {
4        vector<vector<int>>ans;
5        // vector<int>first(1,1);
6        // ans.push_back(first);
7        // if(numsRows==1) return ans;
8        // vector<int>second(2,1);
9        // ans.push_back(second);
10        // if(numsRows==2) return ans;
11        vector<int>res;
12        for(int i=1;i<=numRows;i++){
13            res.clear();
14            for(int j=1;j<=i;j++){
15                if(j==1||j==i){
16                    res.push_back(1);
17                }
18                else{
19                    res.push_back(ans[i-2][j-2]+ans[i-2][j-1]);
20                }
21            }
22            ans.push_back(res);
23        }
24        return ans;
25    }
26};