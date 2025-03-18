class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        long long result = 0;
        deque<int>maxDq, minDq;
        int l=0;

        for (int r=0; r < n; r++) {
            while (!minDq.empty() && nums[minDq.back()] > nums[r]) {
                minDq.pop_back();
            }
            minDq.push_back(r);

            while (!maxDq.empty() && nums[maxDq.back()] < nums[r]) {
                maxDq.pop_back();
            }
            maxDq.push_back(r);

            while (!maxDq.empty() && !minDq.empty() && (nums[maxDq.front()] - nums[minDq.front()]) > 2) {
                if (minDq.front() == l) {
                    minDq.pop_front();
                }
                if (maxDq.front() == l) {
                    maxDq.pop_front();
                }
                l++;
            }
            result += r-l+1;
        }
        return result;
    }
};
