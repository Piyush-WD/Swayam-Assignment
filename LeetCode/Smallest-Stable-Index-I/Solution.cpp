1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4        int n=nums.size();
5        int ma=INT_MIN;
6        int mi=INT_MAX;
7        vector<int>maxArr(n);
8        vector<int>minArr(n);
9        int idx=-1;
10        bool flag=true;
11        for(int i=0;i<n;i++){
12            ma=max(ma,nums[i]);
13            mi=min(mi,nums[n-i-1]);
14            maxArr[i]=ma;
15            minArr[n-i-1]=mi;
16            if(i>=n/2&&flag){
17                if(maxArr[i]-minArr[i]<=k){
18                    idx=i;
19                    flag=false;
20                }
21            }
22        }
23        for(int i=0;i<n/2;i++){
24            if(maxArr[i]-minArr[i]<=k) return i;
25        }
26        if(idx!=-1) return idx;
27        else return -1;
28    }
29};