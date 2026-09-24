1class Solution {
2public:
3    int smallestIndex(vector<int>& nums) {
4        int n=nums.size();
5        for(int i=0;i<n;i++){
6            int sum=0;
7            while(nums[i]){
8                sum+=(nums[i]%10);
9                nums[i]/=10;
10            }
11            if(sum==i) return i;
12        }
13        return -1;
14    }
15};