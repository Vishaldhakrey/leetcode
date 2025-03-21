class Solution {
public:
    int firstOccurances(vector<int>& nums, int target) {
        int first = -1;
        int left  = 0;
        int right = nums.size()-1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return first;
    }
    int lastOccurances(vector<int>& nums, int target) {
        int last = -1;
        int left  = 0;
        int right = nums.size()-1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int first = firstOccurances(nums, target);
        int last = lastOccurances(nums, target);

        return {first, last};
    }
};