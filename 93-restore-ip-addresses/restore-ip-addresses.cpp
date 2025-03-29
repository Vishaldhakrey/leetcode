class Solution {
public:
    int n;
    vector<string>result;
    bool isValid (string str) {
        if (str[0] == '0') {
            return false;
        }
        int num = stoi(str);
        return num <= 255;
    }
    void solve(string &s, string curr, int part, int idx) {
        if (idx == n && part == 4) {
            result.push_back(curr.substr(0, curr.size()-1));
            return;
        }

        if (idx+1 <= n) {
            solve(s, curr+s.substr(idx, 1) + '.', part+1, idx+1);
        }
        if (idx+2 <= n && isValid(s.substr(idx, 2))) {
            solve(s, curr+s.substr(idx, 2) + '.', part+1, idx+2);
        }
        if (idx+3 <= n && isValid(s.substr(idx, 3))) {
            solve(s, curr+s.substr(idx, 3) + '.', part+1, idx+3);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        n = s.size();

        if (n > 12) {
            return result;
        }
        string curr = "";
        int part = 0;

        solve(s, curr, part, 0);
        return result;
    }
};