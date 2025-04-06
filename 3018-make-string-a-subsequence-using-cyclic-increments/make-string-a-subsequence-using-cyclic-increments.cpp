class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        

        int i=0, j=0;

        while (i < m && j < n) {
            int idx1 = str1[i] - 'a';
            int idx2 = str2[j] - 'a';

            if ((idx1 == 25 && idx2 == 0) || (idx2 - idx1) == 1 || (idx2 - idx1) == 0 ) {
                j++;
            }
            i++;
        }

        return j == n;
    }
};