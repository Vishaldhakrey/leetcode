class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();

        string s_str = "";
        string t_str = "";

        for (auto &ch : s) {
            if (!s_str.empty() && ch == '#') {
                s_str.pop_back();
            }
            else if (ch != '#') {
                s_str += ch;
            }
        }

        for (auto &ch : t) {
            if (!t_str.empty() && ch == '#') {
                t_str.pop_back();
            }
            else if (ch != '#') {
                 t_str += ch;
            }
        }

        return s_str == t_str;
    }
};