class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if (k <= 1) {
            return 0;
        }
        int result = 0;
        long long product = 1;

        int l=0, r=0;
        while (r < n) {
            product *= nums[r];

            while (product >= k) {
                product = product/nums[l];
                l++;
            }

            result += (r - l + 1);
            r++;
        }
        return result;
    }
};