class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();

        vector<vector<int>>matrix(26, vector<int>(n+1, 0));

        char prevChar = s[0];
        int len = 0;
        for (int i=0; i<n; i++) {
            char currChar = s[i];
            if (prevChar == currChar) {
                len += 1;
                matrix[currChar - 'a'][len] += 1;
            } else {
                len = 1;
                matrix[currChar - 'a'][len] += 1;
                prevChar = currChar;
            }
        }

        int result = 0;
        for (int i=0; i<26; i++) {
            int cumm_sum = 0;
            for (int j=n; j >= 1; j--) {
                cumm_sum += matrix[i][j];
                if (cumm_sum >= 3) {
                    result = max(result, j);
                }
            }
        } 
        return (result != 0) ? result : -1;
    }
};