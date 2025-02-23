
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<long long, int>> dq;
        long long sum = 0;
        int minLength = INT_MAX;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (sum >= k) {
                minLength = min(minLength, i + 1);
            }

            while (!dq.empty() && sum - dq.front().first >= k) {
                minLength = min(minLength, i - dq.front().second);
                dq.pop_front();
            }

            while (!dq.empty() && sum <= dq.back().first) {
                dq.pop_back();
            }

            dq.push_back({sum, i});
        }

        return (minLength == INT_MAX) ? -1 : minLength;
    }
};
