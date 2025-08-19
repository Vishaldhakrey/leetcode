class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
       int w1i = 0, i = 0;
       int w2j = 0, j = 0;

       int m = word1.size(), n = word2.size();

       while (w1i < m && w2j < n) {

            if (word1[w1i][i] != word2[w2j][j]) {
                return false;
            }
            i++;
            j++;

            if (i == word1[w1i].size()) {
                i = 0;
                w1i++;
            }
            if (j == word2[w2j].size()) {
                j = 0;
                w2j++;
            }
       }

       if (w1i == m && w2j == n) {
        return true;
       }

       return false;
    }
};