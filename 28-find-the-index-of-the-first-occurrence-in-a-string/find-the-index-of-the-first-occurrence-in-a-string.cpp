class Solution {
private :
    void calculateLPS(string needle, vector<int>&lps, int m) {
        int len = 0;
        lps[0] = 0;

        int i=1;
        while(i < m) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if ( len != 0) {
                    len = lps[len-1];
                }
                else {
                    i++;
                }
            }
        }
    }
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m > n) {
            return -1;
        }

        vector<int>lps(m, 0);
        calculateLPS(needle, lps, m);

        int l=0, r=0;
        while (l < n ) {
            if (haystack[l] == needle[r]) {
                l++;
                r++;

                if (r == m) {
                    return l-r;
                }
            }
            else {
                if (r != 0) {
                    r = lps[r-1];
                }
                else {
                    l++;
                }
            }
        }
        return -1;
    }
};