class Solution {
private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
public:
    
    string sortVowels(string s) {
        int n = s.size();

        string vowels = "";

        for (auto &ch : s) {
            if (isVowel(ch)) {
                vowels += ch;
            }
        }

        sort (vowels.begin(), vowels.end());
        int j=0;
        for (int i=0; i<n; i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[j];
                j++;
            }
        }

        return s;
    }
};