class Solution {
public:
    bool detectCapitalUse(string word) {
        int countCapital = 0;

        for (auto &ch : word) {
            if (isupper(ch)) {
                countCapital++;
            }
        }

        if (countCapital == word.size() || countCapital == 0 || (countCapital == 1 && isupper(word[0]))) {
            return true;
        }
        return false;
    }
};