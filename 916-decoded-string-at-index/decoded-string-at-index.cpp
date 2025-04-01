class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n = s.size();

        long long size = 0;
        for (auto &ch : s) {
            if (isdigit(ch)) {
                size *= ch - '0';
            }
            else {
                size += 1;
            }
        }

        for (int i = n-1; i>=0; i--) {
            k = k%size;
            if (k == 0 && isalpha(s[i])) {
                return string(1, s[i]);
            }
            else if (isalpha(s[i])) {
                size -= 1;
            }
            else {
                int num = (s[i]-'0');
                size = size/num;
            }
        }
        return "";
    }
};