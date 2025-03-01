class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(begin(nums), end(nums));

        int maxConsecutiveEle = 1;
        int count = 1;
        int minEle = nums[0];
        for (int i=1; i<n; i++) {
            if (nums[i] == minEle) {
                continue;
            }
            if (nums[i] != minEle+1) {
                minEle = nums[i];
                count = 1;
            }
            else {
                minEle = nums[i];
                count++;
            }
            maxConsecutiveEle = max(maxConsecutiveEle, count);
        }
        return maxConsecutiveEle;
    }
};