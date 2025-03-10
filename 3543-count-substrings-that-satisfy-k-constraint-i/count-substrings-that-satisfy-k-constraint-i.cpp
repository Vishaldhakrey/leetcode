class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();

        int result = 0;
        int cnt0   = 0;
        int cnt1   = 0;
        int l=0, r=0;

        while (r < n) {
            if (s[r] == '0') {
                cnt0++;
            }
            else {
                cnt1++;
            }
            while (cnt1 > k && cnt0 > k) {
                if (s[l] == '0') {
                    cnt0--;
                }
                else {
                    cnt1--;
                }
                l++;
            }
            result += (r-l+1);
            r++;
        }

        return result;
    }
};