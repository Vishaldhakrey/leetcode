class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>result(n, -1);
        vector<long long>preSum(n, 0);

        if (n < k) return result;


        long long sum = 0;
        for (int i=0; i<n; i++) {
            sum += nums[i];
            preSum[i] = sum;
        }

        for (int i=k; i<n-k; i++) {
            long long sumToiPlusK = preSum[i+k];
            long long removedSum = (i-k-1 < 0) ? 0 : preSum[i-k-1];
            int average = k+k+1;
            int totalAverageOfi = (sumToiPlusK - removedSum) / average;
            result[i] = totalAverageOfi;
        }
        return result;
    }
};