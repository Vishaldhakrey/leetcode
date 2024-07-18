#include <vector>
#include <stack>

class Solution {
public:
    long long subArrayRanges(std::vector<int>& nums) {
        long long res = 0;
        stack<int> s1, s2;

        for (int i = 0; i <= nums.size(); ++i) {
            while (!s1.empty() && (i == nums.size() || nums[s1.top()] < nums[i])) {
                int curInd = s1.top(); s1.pop();
                int leftBound = s1.empty() ? -1 : s1.top();
                int rightBound = i;

                res += (curInd - leftBound) * (rightBound - curInd) * (long long) nums[curInd];
            }

            while (!s2.empty() && (i == nums.size() || nums[s2.top()] > nums[i])) {
                int curInd = s2.top(); s2.pop();
                int leftBound = s2.empty() ? -1 : s2.top();
                int rightBound = i;

                res -= (curInd - leftBound) * (rightBound - curInd) * (long long) nums[curInd];
            }

            if (i < nums.size()) {
                s1.push(i);
                s2.push(i);
            }
        }

        return res;
    }
};
