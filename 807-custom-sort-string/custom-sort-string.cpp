class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);

        // Count frequency of characters in s
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string result = "";

        // Append characters in the order specified
        for (char ch : order) {
            while (freq[ch - 'a'] > 0) {  // Append all occurrences
                result += ch;
                freq[ch - 'a']--;
            }
        }

        // Append remaining characters that were not in 'order'
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                result += char(i + 'a');
                freq[i]--;
            }
        }

        return result;
    }
};
