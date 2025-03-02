class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        long long maxWindowSum = 0;
        long long currWindowSum = 0;

        int l=0, r=0;
        unordered_set<int>st;
        while (r < n) {
            while (st.count(nums[r])) {
                currWindowSum -= nums[l];
                st.erase(nums[l]);
                l++;
            }

            currWindowSum += nums[r];
            st.insert(nums[r]);
            if ((r-l+1) == k) {
                maxWindowSum = max(maxWindowSum, currWindowSum);
                currWindowSum -= nums[l];
                st.erase(nums[l]);
                l++;
            }
            r++;
        }
        return maxWindowSum;
    }
};