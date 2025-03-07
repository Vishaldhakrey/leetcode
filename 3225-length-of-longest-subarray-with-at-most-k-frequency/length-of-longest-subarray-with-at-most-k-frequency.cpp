class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return 0;
        unordered_map<int, int>freq_map;
        int longestSubarray = 0;
        int l=0, r=0;

        while (r < n) {
            freq_map[nums[r]]++;

            while (freq_map[nums[r]] > k) {
                freq_map[nums[l]]--;
                l++;
            }

            longestSubarray = max(longestSubarray, r-l+1);
            r++;
        }
        return longestSubarray;
    }
};