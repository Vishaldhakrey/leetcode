class Solution {
private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
public:
    
    string sortVowels(string s) {
        int n = s.size();

        unordered_map<char, int> mp;

        for (auto &ch : s) {
            if (isVowel(ch)) {
                mp[ch]++;
            }
        }
        string vowels = "AEIOUaeiou";
        int j=0;
        for (int i=0; i<n; i++) {
            if (isVowel(s[i])) {
                while (mp[vowels[j]] == 0) {
                    j++;
                }

                s[i] = vowels[j];
                mp[vowels[j]]--;
            }
        }

        return s;
    }
};