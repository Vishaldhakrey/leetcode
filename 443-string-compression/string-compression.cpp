class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        if (n == 0) {
            return 0;
        }
        int i = 0;
        int j = 0;

        while (j < n) {
            char curr_ch = chars[j];
            int cnt = 0;

            while (j < n && chars[j] == curr_ch) {
                cnt++;
                j++;
            } 
            chars[i++] = curr_ch;
            if (cnt > 1) {
                string cnt_of_ch = to_string(cnt);
                for (char &ch : cnt_of_ch) {
                    chars[i++] = ch;
                }
            }
        }
        return i;
    }
};