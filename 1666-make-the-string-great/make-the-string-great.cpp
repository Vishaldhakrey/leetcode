class Solution {
public:
    string makeGood(string s) {
        int j=0;
        while(!s.empty() && j<s.size()-1) {
            if (tolower(s[j]) == tolower(s[j+1]) && s[j] != s[j+1]) {
                s.erase(j, 2);
                j=0;
            }
            else {
            j++;
            }
        }
        return s;
    }
};