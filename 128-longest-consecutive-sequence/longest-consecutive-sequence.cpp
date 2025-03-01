class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int longest = 1;
        unordered_set<int>st(nums.begin(), nums.end());

        for(auto &itr : st) {
            if (st.find(itr-1) == st.end()) {
                int count = 1;
                int start = itr;
                while (st.find(start + 1) != st.end()) {
                    count++;
                    start++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};