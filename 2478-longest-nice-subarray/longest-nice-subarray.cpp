class Solution {
public:
    bool isNice(vector<int>& nums, int i, int j) {
        int mask = 0;

        for (int l=i; l<=j; l++) {
            if ((mask & nums[l]) != 0) {
                return false;
            }
            mask = (mask | nums[l]);
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int result = 1;
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                if (isNice(nums, i, j)) {
                    result = max(result, j-i+1);
                }
                else {
                    break;
                }
            }
        }
        return result;
    }
};