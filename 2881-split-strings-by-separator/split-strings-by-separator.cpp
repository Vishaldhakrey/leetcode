class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string>res;
        for (auto &word : words) {
            int start = 0;
            for (int i=0; i<=word.size(); i++) {
                if (i == word.size() || word[i] == separator) {
                    int length = i - start;

                    if (length > 0) {
                        res.push_back(word.substr(start, length));
                    }

                    start = i+1;

                }
            }
        }
        return res;
    }
};