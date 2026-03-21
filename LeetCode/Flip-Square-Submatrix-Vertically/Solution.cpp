1class Solution {
2public:
3    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
4        int n=grid.size();
5        int m=grid[0].size();
6        for(int i=0;i<k;i++){
7            int i1=x;
8            int j1=y;
9            int i2=x+k-1;
10            int j2=y;
11            while(i1<i2){
12                int temp = grid[i1][j1];
13                grid[i1][j1]=grid[i2][j2];
14                grid[i2][j2]=temp;
15                i1++;
16                i2--;
17            }
18            y++;
19        }
20        return grid;
21    }
22};