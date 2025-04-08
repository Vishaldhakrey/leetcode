class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();

        string rev = s;
        reverse(rev.begin(), rev.end());
        for (int i=0; i<n; i++) {
            if (!memcmp(s.c_str(), rev.c_str()+i, n-i)) { //compare the values by without creating temp variable and it will return 0, if true
                return rev.substr(0, i) + s;
            }
        }
        return rev + s;
    }
};