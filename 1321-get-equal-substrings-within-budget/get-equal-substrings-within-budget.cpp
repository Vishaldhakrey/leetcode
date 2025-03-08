class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        int maxLen = 0;
        int l=0, r=0;
        int curr_cost = 0;

        while (r < n) {
            curr_cost += abs(s[r] - t[r]);

            while (curr_cost > maxCost) {
                curr_cost -= abs(s[l] - t[l]);
                l++;
            }

            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};