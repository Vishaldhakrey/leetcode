class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        vector<int>lastIdx(26);
        vector<bool>seen(26, false);

        for (int i=0; i<n; i++) {
            lastIdx[s[i]-'a'] = i;
        }

        string result;

        for (int i=0; i<n; i++) {
            char ch = s[i];

            if (seen[ch-'a'] == true) {
                continue;
            }
            while (!result.empty() && result.back() > ch && lastIdx[result.back()-'a'] > i) {
                seen[result.back()-'a'] = false;
                result.pop_back();
            }
            result.push_back(ch);
            seen[ch-'a'] = true;
        }
        return result;
    }
};