class Solution {
public:
    long long reqTime(vector<int>& piles, int hourly) {
        long long total = 0;
        for (int bananas : piles) {
            total += (bananas + (long long)hourly - 1) / hourly;
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxB = *max_element(piles.begin(), piles.end());
        int start = 1, end = maxB, ans = maxB;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (reqTime(piles, mid) <= h) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
