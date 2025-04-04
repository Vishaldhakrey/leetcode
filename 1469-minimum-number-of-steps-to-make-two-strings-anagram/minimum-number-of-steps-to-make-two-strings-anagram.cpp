class Solution {
public:
    int minSteps(string s, string t) {
        int n = t.size();

        vector<int>freq(26, 0);
        for (auto &ch : s) {
            freq[ch - 'a']++;
        }

        int steps = 0;
        for (auto &ch : t) {
            if (freq[ch - 'a'] == 0) {
                steps += 1;
            } else {
                freq[ch - 'a']--;
            }
        }
        return steps;
    }
};