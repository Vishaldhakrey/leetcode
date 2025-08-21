class Solution {
public:
    unordered_map<string, bool>mp;
    bool isConcatenated(string word, unordered_set<string>&st) {
        
        if (mp.find(word)!=mp.end()) {
            return mp[word];
        }

        int len = word.size();
        for (int i=0; i<len; i++) {

            string prefix_str = word.substr(0, i+1);
            string suffix_str = word.substr(i+1);

            if ((st.find(prefix_str) != st.end() && isConcatenated(suffix_str, st)) || (st.find(prefix_str) != st.end() && st.find(suffix_str) != st.end())) {
                return mp[word] = true;
            }
        }
        return mp[word] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>res;
        mp.clear();

        unordered_set<string>st(words.begin(), words.end());
        
        for (auto &word: words) {
            if (isConcatenated(word, st)) {
                res.push_back(word);
            }
        }

        return res;

    }
};