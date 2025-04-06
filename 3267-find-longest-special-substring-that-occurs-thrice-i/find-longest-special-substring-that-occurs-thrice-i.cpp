class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();

        unordered_map<string, int>mp;

        for (int i=0; i<n; i++) {
            string curr;
            for (int j=i; j<n; j++) {
                if (s[j] == s[i]) {
                    curr += s[j];
                    mp[curr]++;
                }
                else {
                    break;
                }
            }
        }

        string result = "";
        for (auto &it : mp) {
            string str = it.first;
            int cnt = it.second;
            if (cnt >= 3 && str.size() > result.size()) {
                result = str;
            }
        }

        return !result.empty() ? result.size() : -1;
    }
};