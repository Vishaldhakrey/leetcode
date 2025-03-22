class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || nums[0] != nums[1]) {
            return nums[0];
        }
        if (nums[n - 1] != nums[n - 2]) {
            return nums[n - 1];
        }

        int left = 1, right = n - 2;
        
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == nums[mid ^ 1]) {  // Checking pairs
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];  // The single element
    }
};
