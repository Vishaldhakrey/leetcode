class Solution {
private:
    unordered_map<string, bool>mp;
    bool isConcatenated(string str, unordered_set<string> &st) {

        if (mp.find(str) != mp.end()) {
            return mp[str];
        }

        int l = str.size();

        for (int i=0; i<l; i++) {
            string prefix = str.substr(0, i+1);
            string suffix = str.substr(i+1);

            if ((st.find(prefix) != st.end() && isConcatenated(suffix, st)) ||
                (st.find(prefix) != st.end() && st.find(suffix) != st.end())) {
                    return mp[str] = true;
                }
        }
        return mp[str] = false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();

        vector<string>result;

        unordered_set<string>st (words.begin(), words.end());


        for (auto &word : words) {
            if (isConcatenated(word, st)) {
                result.push_back(word);
            }
        }
        return result;
    }
};