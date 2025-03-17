class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int cnt_a = 0;
        int cnt_b = 0;
        int cnt_c = 0;

        for (auto &ch : s) {
            if (ch == 'a') {
                cnt_a++;
            }
            else if (ch == 'b') {
                cnt_b++;
            }
            else if (ch == 'c') {
                cnt_c++;
            }
        }

        if (cnt_a < k || cnt_b < k || cnt_c < k) {
            return -1;
        }

        int notDeletedWindow = 0;
        int i=0, j=0;
        while (j < n) {
            char ch = s[j];
            if (ch == 'a') {
                cnt_a--;
            }
            else if (ch == 'b') {
                cnt_b--;
            }
            else if (ch == 'c') {
                cnt_c--;
            }

            while (i <= j  && (cnt_a < k || cnt_b < k || cnt_c < k)) {
                char ch_left = s[i];
                if (ch_left == 'a') {
                    cnt_a++;
                }
                else if (ch_left == 'b') {
                    cnt_b++;
                }
                else if (ch_left == 'c') {
                    cnt_c++;
                }
                i++;
            }
            notDeletedWindow = max(notDeletedWindow, j-i+1);
            j++;
        }
        return n - notDeletedWindow;
    }
};