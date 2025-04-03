class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();

        int s_skip = 0;
        int t_skip = 0;
        int i = n-1;
        int j = m-1;
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    s_skip++;
                    i--;
                }
                else if (s_skip > 0) {
                    s_skip--;
                    i--;
                }
                else {
                    break;
                }
            }

            while (j >= 0) {
                if (t[j] == '#') {
                    t_skip++;
                    j--;
                }
                else if (t_skip > 0) {
                    t_skip--;
                    j--;
                }
                else {
                    break;
                }
            }

            char first = i < 0 ? '$' : s[i];
            char second = j < 0 ? '$' : t[j];

            if (first != second) {
                return false;
            }
            i--;
            j--;
        }

        return true;
    }
};