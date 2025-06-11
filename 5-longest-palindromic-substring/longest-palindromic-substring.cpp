class Solution {
    int startIdx=0;
    int resultLength = 0;
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if (n < 2) {
            return s;
        }

        for (int start=0; start < n-1; start++) {
            expandRange(s, start, start, n);
            expandRange(s, start, start+1, n);
        }

        return s.substr(startIdx, resultLength);
    }

    void expandRange(string s, int begin, int end, int n) {
        while (begin >= 0 && end <= n-1 && s[begin] == s[end]) {
            begin--;
            end++;
        }

        if (resultLength < end-begin-1) {
            startIdx = begin+1;
            resultLength = end-begin-1;
        }
    }
};