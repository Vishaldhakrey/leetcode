class Solution {
private:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

public:
    bool halvesAreAlike(string s) {
        int n = s.size();

        int leftVowelCnt = 0;
        for (int i=0; i<n/2; i++) {
            if (isVowel(s[i])) {
                leftVowelCnt++;
            }
        }
        int rightVowelCnt = 0;
        for (int i=n/2; i<n; i++) {
            if (isVowel(s[i])) {
                rightVowelCnt++;
            }
        }

        return leftVowelCnt == rightVowelCnt;
    }
};