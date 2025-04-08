class Solution {
public:
//TimeComplexity of this is O(n3)
    int maximumLength(string s) {
        int n = s.size();

        vector<vector<int>>matrix(26, vector<int>(n+1, 0));
        int len = 0;
        char prevChar = s[0];
        for (int i=0; i<n; i++) { //O(n)
            char ch = s[i];
            if (ch == prevChar) {
                len += 1;
                matrix[ch - 'a'][len] += 1;
            }
            else {
                len = 1;
                matrix[ch - 'a'][len] += 1;
                prevChar = ch;
            }
        }

        int result = 0;
        
        for (int i=0; i<26; i++) {
            int cumSum = 0;
            for (int j=n; j>= 1; j--) {
                cumSum += matrix[i][j];
                if (cumSum >= 3) {
                    result = max(result, j);
                    break;
                }
            } 
        }
        return result != 0 ? result : -1;
    }
};