class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();

        int cnt = 0;
        unordered_map<char, int>freq;
        int maxLen = 0;

        for (int r=0; r < n; r++) {
            if (r > 0 && word[r] < word[r-1]) {
                freq.clear();
                cnt = 0;
            }
            
            freq[word[r]]++;
            cnt++;

            if (freq['a'] > 0 && freq['e'] > 0 && freq['i'] > 0 && freq['o'] > 0 && freq['u'] > 0) {
                maxLen = max(maxLen, cnt);
            }
        }
        return maxLen;
    }
};