class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_set<char>st;
        int maxLen = 0;
        int l=0, r=0;

        while (r < n) {
            char ch = s[r];
            while (st.count(ch)) {
                st.erase(s[l]);
                l++;
            }
            st.insert(ch);
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};