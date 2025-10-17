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
    bool isKMPContain(vector<int>&LPS, string&s) {
        string temp = s + s;
        int n = s.size();
        int end = (n*2)-1;
        int i=1;
        int j=0;
        while (i < end) {
            if (temp[i] == s[j]) {
                i++;
                j++;
                if (j == s.size()){
                    return true;
                }
            }
            else if (j > 0) {
                j = LPS[j-1];
            }
            else {
                i++;
            }
        }
        return false;
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        if (n <= 1) {
            return false;
        }
        vector<int>LPS(n, 0);
        KMP(s, LPS);

        return isKMPContain(LPS, s);
    }
};