class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u');
    }
    int beautifulSubstrings(string s, int k) {
        int n = s.size();

        int cnt = 0;
        for (int i=0; i<n; i++) {
            int cons = 0;
            int vowel = 0;
            for (int j=i; j<n; j++) {
                if (isVowel(s[j])) {
                    vowel += 1;
                }
                else {
                    cons += 1;
                }

                if (cons == vowel && (cons * vowel)%k == 0) {
                    cnt += 1;
                }
            }
        }

        return cnt;
    }
};