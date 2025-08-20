class Solution {
    
public:
    bool check(string word, char first, char last) {
        for (auto &ch : word) {
            if (ch < first || ch > last) {
                return false;
            }
        }
        return true;
    }

    bool detectCapitalUse(string word) {
        if (check(word, 'A', 'Z') || check(word, 'a', 'z') || check(word.substr(1), 'a', 'z')) {
            return true;
        }
        return false;
    }
};