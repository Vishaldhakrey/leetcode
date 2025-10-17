class Solution {
public:
    void KMP(string &s, vector<int>&LPS) {
        int n = LPS.size();
        int len = 0;
        int i = 1;
        LPS[0] = 0;
        while(i < n) {
            if (s[i] == s[len]) {
                len++;
                LPS[i] = len;
                i++;
            } 
            else if (len != 0) {
                len = LPS[len-1];
            }
            else {
                LPS[i] = 0;
                i++;
            }
        }
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        vector<int>LPS(n, 0);
        KMP(s, LPS);

        int len = LPS[n-1];

        return len > 0 && n % (n - len) == 0;
    }
};