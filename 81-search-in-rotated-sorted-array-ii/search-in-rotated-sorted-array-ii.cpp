class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int left  = 0;
        int right = n-1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }
            //special case when arr[left] = arr[right] = arr[mid] like [1, 1, 1, 1, 1, 1, 2, 1, 1] and target = 2;
            if (nums[mid] == nums[right] && nums[mid] == nums[left]) {
                left++;
                right--;
            }
            else if (nums[mid] <= nums[right]) {
                if (nums[mid] < target && target <= nums[right] ) {
                    left = mid+1;
                }
                else {
                    right = mid - 1;
                }
            }
            else {
                if (nums[mid] > target && target >= nums[left]) {
                    right = mid-1;
                }
                else {
                    left = mid+1;
                }
            }
        }
    return false;

    }
};