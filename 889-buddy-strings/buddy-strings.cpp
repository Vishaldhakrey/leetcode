class Solution {
private:
    bool check(string s) {
        vector<int>freq(26, 0);

        for (auto &ch : s) {
            freq[ch - 'a']++;

            if (freq[ch - 'a'] > 1) {
                return true;
            }
        }
        return false;
    }
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        if (s == goal) {
            return check(s);
        }

        vector<int>indx;

        for (int i=0; i<s.size(); i++) {
            if (s[i] != goal[i]) {
                indx.push_back(i);
            }

            
        }
        if (indx.size() != 2) {
            return false;
        }

        swap(s[indx[0]], s[indx[1]]);

        return s == goal;
    }
};