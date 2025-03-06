class Solution {
public:
    int findMaxFreq(int idx, int k, vector<int> &nums, vector<long long>& preSum) {
        int target = nums[idx];

        int i = 0; 
        int j = idx;
        int result = idx;
        
        while (i <= j) {
            int mid = i + (j-i)/2;
            
            long count     = (idx - mid + 1);
            long windowSum = (count * target);
            long currSum   = preSum[idx] - (mid > 0 ? preSum[mid-1] : 0);
            int opn = windowSum - currSum;

            if (opn <= k) {
                result = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }

        }
        return idx - result + 1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long>preSum(n, 0);

        sort(nums.begin(), nums.end());
        preSum[0] = nums[0];

        for (int i=1; i<n; i++) {
            preSum[i] = preSum[i-1] + nums[i];
        }

        int result = 0;
        for (int i=0; i<n; i++) {
            result = max(result, findMaxFreq(i, k, nums, preSum));
        }
        return result;
    }
};