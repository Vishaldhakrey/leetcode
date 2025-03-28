class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string result = "";
        int j=0;
        while(j<s.size()) {
            if (!result.empty() && tolower(result.back()) == tolower(s[j]) && result.back() != s[j]) {
                result.pop_back();
            }
            else {
                result.push_back(s[j]);
            }
            j++;
        }
        return result;
    }
};