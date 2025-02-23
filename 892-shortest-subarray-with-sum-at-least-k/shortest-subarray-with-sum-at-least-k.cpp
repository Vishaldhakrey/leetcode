#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int minSubarrayWindow = INT_MAX;
        long long sum = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, -1}); // Handle prefix sum scenario

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            while (!pq.empty() && sum - pq.top().first >= k) {
                auto [prevSum, idx] = pq.top();
                pq.pop();
                minSubarrayWindow = min(minSubarrayWindow, i - idx);
            }

            pq.push({sum, i});
        }

        return (minSubarrayWindow == INT_MAX) ? -1 : minSubarrayWindow;
    }
};
