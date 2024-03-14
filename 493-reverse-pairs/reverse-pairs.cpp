class Solution {
public:
    int merge(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int i = left;
        int j = mid + 1;
        vector<int> temp;
        
        // Merge and count pairs
        while (i <= mid && j <= right) {
            if ((long long)nums[i] > 2LL * (long long)nums[j]) {
                count += mid - i + 1;  // Count pairs
                j++;
            } else {
                i++;
            }
        }
        
        // Merge the sorted halves
        i = left;
        j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= right) {
            temp.push_back(nums[j]);
            j++;
        }
        
        // Copy back to original vector
        for (int k = left; k <= right; k++) {
            nums[k] = temp[k - left];
        }
        
        return count;
    }

    int mergeSort(vector<int>& nums, int left, int right) {
        int count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            count += mergeSort(nums, left, mid);
            count += mergeSort(nums, mid + 1, right);
            count += merge(nums, left, mid, right);
        }
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
