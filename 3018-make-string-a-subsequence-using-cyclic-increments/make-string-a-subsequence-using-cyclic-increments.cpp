class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        

        int i=0, j=0;

        while (i < m && j < n) {
            char ch1 = str1[i];
            char ch2 = str2[j];

            if ((ch1 == ch2) || ch1+1 == ch2 || ch1 == ch2+25 ) {
                j++;
            }
            i++;
        }

        return j == n;
    }
};