class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();

        int minKPosition = -1;
        int maxKPosition = -1;
        int cultpritIndex = -1;
        long long result = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                cultpritIndex = i;
            }

            if (nums[i] == minK) {
                minKPosition = i;
            }
            if (nums[i] == maxK) {
                maxKPosition = i;
            }

            long long smaller = min(minKPosition, maxKPosition);
            long long temp = smaller - cultpritIndex;

            result += (temp < 0) ? 0 : temp;
        }
        return result;
    }
};