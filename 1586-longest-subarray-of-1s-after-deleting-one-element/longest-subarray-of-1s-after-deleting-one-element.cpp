class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int zero = 0;
        int l=0, r=0;
        int maxOnes = 0;

        while (r < n) {
            if (nums[r] == 0) {
                zero += 1;
            }
            while (zero > 1) {
                if (nums[l] == 0) zero--;
                l++;
            }

            maxOnes = max(maxOnes, (r-l));
            r++;
        }
        return maxOnes;
    }
};