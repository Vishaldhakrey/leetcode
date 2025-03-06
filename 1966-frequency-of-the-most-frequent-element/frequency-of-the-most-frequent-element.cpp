class Solution {
public:
    
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int result = 0;
        long long windowSum = 0;
        int left = 0;
        int right = 0;

        while (right < n) {
            long long target = nums[right];

            windowSum += nums[right];

            while ((target * (right - left + 1) - windowSum) > k) {
                windowSum -= nums[left];
                left++;
            }

            result = max(result, right-left+1);
            right++;
        }
        return result;
    }
};