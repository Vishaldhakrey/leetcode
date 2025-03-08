class Solution {
    typedef pair<int, int> p;
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        multiset<int>multi_set;

        int maxLen = 0;
        int l=0, r=0;

        while (r < n) {
            multi_set.insert(nums[r]);

            while (*multi_set.rbegin() - *multi_set.begin() > limit) {
                multi_set.erase(multi_set.find(nums[l]));
                l++;
            }

            maxLen = max (maxLen, r-l+1);
            r++;

        }
        return maxLen;
    }
};