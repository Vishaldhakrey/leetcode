class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return {};

        vector<int>result(n-k+1, -1);
        
        int r=1;
        int count = 1;
        for (; r<k; r++) {
            if (nums[r]-1 != nums[r-1]) {
                count = 1;
            }
            else {
                count++;
            }
        }

        if (count == k) {
            result[0] = nums[k-1];
        }

        int l = 1;
        r = k;

        while (r < n) {
            if (nums[r]-1 == nums[r-1]) {
                count++;
            }
            else {
                count = 1;
            }
            if (count >= k) {
                result[l] = nums[r];
            }
            r++;
            l++;
        }
        return result;
    }
};