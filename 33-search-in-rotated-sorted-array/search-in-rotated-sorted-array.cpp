class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int left  = 0;
        int right = n-1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            //sorted part
            else if (nums[mid] < nums[right]) {
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            else {
                if (nums[mid] >= target && target >= nums[left]) {
                    right = mid-1;
                }
                else {
                    left = mid+1;
                }
            }
        }
        return -1;
    }
};