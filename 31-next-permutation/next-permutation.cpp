class Solution {
public:
    void nextValidPrmutation(vector<int>& nums) {
        int n = nums.size();
        int i=n-2;
        for ( ;i>=0; i--) {
            if (nums[i] < nums[i+1]) {
                break;
            }
        }
        if (i >= 0) {
            for (int j=n-1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    swap(nums[j], nums[i]);
                    break;
                }
            }
        }
        reverse(nums.begin()+(i+1), nums.end());
        return;
    }
    void nextPermutation(vector<int>& nums) {
        nextValidPrmutation(nums);
        return;
    }
};