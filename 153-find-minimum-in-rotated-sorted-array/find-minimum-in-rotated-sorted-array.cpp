class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If middle element is smaller than the rightmost element, min must be on the left half (including mid)
            if (nums[mid] < nums[right]) {
                right = mid;
            }
            // Otherwise, min must be in the right half (excluding mid)
            else if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // When nums[mid] == nums[right], reduce search space by decrementing right
            else {
                right--;
            }
        }

        return nums[left];
    }
};
