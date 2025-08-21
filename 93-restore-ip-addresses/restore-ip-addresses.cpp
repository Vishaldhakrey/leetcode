class Solution {
public:
    int n;
    bool isValid(string str) {
        if (str[0] == '0') {
            return false;
        }
        int num = stoi(str);
        return num <= 255;
    }
    void findValidIpAddresses(string &s, vector<string>&result, string curr, int part, int idx) {
        if (part > 4) {
            return;
        }
        if (idx == n && part == 4) {
            curr.pop_back();
            result.push_back(curr);
            return;
        }

        if (idx+1 <= n) {
            findValidIpAddresses(s, result, curr + s.substr(idx, 1) + '.', part+1, idx+1);
        }

        if (idx+2 <= n && isValid(s.substr(idx, 2))) {
            findValidIpAddresses(s, result, curr + s.substr(idx, 2) + '.', part+1, idx+2);
        }

        if (idx+2 <= n && isValid(s.substr(idx, 3))) {
            findValidIpAddresses(s, result, curr + s.substr(idx, 3) + '.', part+1, idx+3);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>result;
        n = s.size();
        if (n > 12) {
            return result;
        }

        int part = 0;
        string curr = "";
        findValidIpAddresses(s, result, curr, part, 0);

        return result;
    }
};