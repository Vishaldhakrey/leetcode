class Solution {
public:
    
    
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_set<char>letters;

        for (auto &ch : s) {
            letters.insert(ch);
        }

        int result = 0;

        for (auto &letter : letters) {
            int first_idx = -1;
            int last_idx = -1;

            for (int i=0; i<n; i++) {
                if (s[i] == letter) {
                    if (first_idx == -1) {
                        first_idx = i;
                    }
                    last_idx = i;
                }
            }

            unordered_set<char>middle_chars;
            for (int middle = first_idx+1; middle <= last_idx-1; middle++) {
                middle_chars.insert(s[middle]);
            }

            result += middle_chars.size();

        }

        return result;
    }
};