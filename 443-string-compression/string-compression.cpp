class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        
        int prev = 0;
        int next = 0;
        while (next < n) {
            char ch = chars[next];
            int cnt = 0;

            while (next < n && ch == chars[next]) {
                cnt++;
                next++;
            }

            chars[prev++] = ch;

            if (cnt > 1) {
                string nums = to_string(cnt);
                for (auto num : nums) {
                    chars[prev++] = num;
                }
            } 
        }
        return prev;
    }
};