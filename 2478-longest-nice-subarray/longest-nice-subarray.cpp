class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int result = 1;
        int mask   = 0;
        int l = 0, r = 0;

        while (r < n) {
            while ((mask & nums[r]) != 0) {
                mask = (mask ^ nums[l]);
                l++;
            }
            result = max (result, r-l+1);
            mask = (mask | nums[r]);
            r++;
        }
        return result;
    }
};