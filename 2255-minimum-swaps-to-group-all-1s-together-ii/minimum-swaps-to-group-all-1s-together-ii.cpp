class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int totalOnes = std::count(nums.begin(), nums.end(), 1);

        int l=0, r=0;
        int currWindowCount = 0;
        int maxWindowCount = 0;
        int min_swaps = INT_MAX;

        while (r < 2*n) {
            if (nums[r%n] == 1) {
                currWindowCount += 1;
            }

            if ((r-l+1) > totalOnes) {
                currWindowCount -= nums[l%n];
                l++;
            }
            maxWindowCount = max(currWindowCount, maxWindowCount);
            r++;
        }
        return totalOnes - maxWindowCount;
    }
};