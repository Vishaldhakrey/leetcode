class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>result(n, -1);

        if (n < 2*k+1) return result;


        long long preSum = 0;
        long long windowSum = 0;
        int l=0, r=0;

        while (r < n) {
            windowSum += nums[r];

            if ((r-l+1) == (2*k+1)) {
                int windowAvg = (windowSum-preSum) / (2*k+1);
                result[r-k] =windowAvg;
                preSum += nums[l];
                l++;
            }
            r++;
        }
        return result;
    }
};