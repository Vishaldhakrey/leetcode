
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        int minLen = INT_MAX;
        long long sum = 0;

        deque<pair<long long, int>>dq;

        for (int i=0; i<n; i++) {
            sum += nums[i];
            if (sum >= k) {
                minLen = min(minLen, i+1);
            }
            //Shrinking the window
            while (!dq.empty() && (sum - dq.front().first) >= k) {
                minLen = min(minLen, i - dq.front().second);
                dq.pop_front();
            }

            //stored sum in dq while maintaining the monotonic increasing property
            while (!dq.empty() && sum <= dq.back().first) {
                dq.pop_back();
            }

            dq.push_back({sum, i});
        }

        return (minLen == INT_MAX) ? -1 : minLen;
    }
};
