class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();

        int cnt = 1;
        int length = 1;
        int maxLen = 0;

        for (int r=1; r < n; r++) {
            if (word[r] >= word[r-1]) {
                length++;

                if (word[r] > word[r-1]) {
                    cnt++;
                }
            }
            else {
                length = 1;
                cnt = 1;
            }

            if (cnt == 5) {
                maxLen = max(maxLen, length);
            }
        }
        return maxLen;
    }
};