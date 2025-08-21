class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        int start = -1;
        int l=0, r=0;
        while(l < n) {
            if (haystack[l] == needle[r]) {
                if (start == -1) {
                    start = l;
                }
                r++;

                if (r == m) {
                    return start;
                }
            }
            else {
                if (start != -1) {
                    l = start;
                }
                start = -1;
                r=0;
            }
            l++;
        }
        return -1;
    }
};