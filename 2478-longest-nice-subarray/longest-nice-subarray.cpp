class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int result = 1;
        int mask   = 0;
        int l = 0, r = 0;

        while (r < n) {
            // If the mask and nums[r] is not 0 than shrink the window by removing the nums[l] by using XOR
            while ((mask & nums[r]) != 0) { 
                mask = (mask ^ nums[l]);
                l++;
            }
            result = max (result, r-l+1);
            //mask store the all Values by doing OR (sum)
            mask = (mask | nums[r]);
            r++;
        }
        return result;
    }
};