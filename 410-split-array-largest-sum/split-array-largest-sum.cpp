class Solution {
private:
    int isSplitted(vector<int>&nums, int splitNum, int n) {
        int spltCnt = 1;
        long long splitSum = 0;

        for (int i=0; i<n; i++) {
            if (splitSum + nums[i] <= splitNum) {
                splitSum += nums[i];
            }else {
                spltCnt++;
                splitSum = nums[i];
            }
        }
        return spltCnt;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        if (n < k) {
            return -1;
        }

        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left <= right) {
            int mid = left + (right-left)/2;

            int sptCnt = isSplitted(nums, mid, n);

            if (sptCnt <= k) {
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        return left;
    }
};