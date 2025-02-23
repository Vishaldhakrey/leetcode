class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minSizeWindow = INT_MAX;
        int low=0;
        int high=0;
        int sum=0;
        while(high<nums.size()) {
            
            sum += nums[high];
            high++;
            while(sum>=target) {
                int currentWindowSize = high-low;
                minSizeWindow = min(minSizeWindow, currentWindowSize);
                sum-=nums[low];
                low++;
            }
        }
        return minSizeWindow==INT_MAX ? 0 : minSizeWindow;
    }
};