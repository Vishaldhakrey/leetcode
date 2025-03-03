class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();

        unordered_map<char, int>um;
        for (auto &ch : t) {
            um[ch]++;
        }

        int left=0, right=0;
        int requiredCount = t.size();
        int minStart = 0;
        int minWindow = INT_MAX;

        while (right < n) {
            char ch = s[right];
            if (um[ch] > 0) {
                requiredCount--;
            }
            um[ch]--;

            while (requiredCount == 0) {
                if (minWindow > right-left+1) {
                    minWindow = right-left+1;
                    minStart = left;
                }
                char ch_i = s[left];
                um[ch_i]++;
                if (um[ch_i]>0) {
                    requiredCount++;
                }
                left++;
            }
            right++;
        }

        return (minWindow == INT_MAX) ? "" : s.substr(minStart, minWindow);
    }
};