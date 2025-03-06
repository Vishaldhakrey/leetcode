class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> dp(nums);
        deque<int>dq;
        int maxSum = dp[0];


        for (int i=0; i<n; i++) {
            while (!dq.empty() && dq.front() < i-k) {
                dq.pop_front();
            }
            if(!dq.empty()) {
                dp[i] = max(dp[i], nums[i]+dp[dq.front()]);
            }
            while (!dq.empty() && dp[i] >= dp[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(i);

            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};