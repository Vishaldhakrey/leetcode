class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int result = 1;
        for (int i=0; i<n; i++) {
            int mask = 0;

            for (int l=i; l<n; l++) {
                if ((mask & nums[l]) != 0) {
                    break;
                }
                result = max(result, l-i+1);
                mask = (mask | nums[l]);
            }
        }
        return result;
    }
};