1class Solution {
2public:
3    int maxScore(vector<int>& cardPoints, int k) {
4        int lsum=0, rsum=0, maxsum=0;
5        int n=cardPoints.size();
6        for(int i=0;i<k;i++) lsum+=cardPoints[i];
7        maxsum=lsum;
8        int ridx=n-1;
9        for(int i=k-1;i>=0;i--){
10            lsum-=cardPoints[i];
11            rsum+=cardPoints[ridx];
12            ridx--;
13            maxsum = max(maxsum, lsum+rsum);
14        }
15        return maxsum;
16    }
17};