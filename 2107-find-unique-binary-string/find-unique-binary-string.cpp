class Solution {
public:
    int n;
    void findValidNum(string &s, unordered_set<string> &st,string & result, int ind) {
        if (ind == n) {
            if(st.find(s) == st.end()) {
                result = s;
            }
            return;
        }
        
        s[ind] = '1';
        findValidNum(s, st, result, ind+1);

        if (!result.empty()) {
            return;
        }
        
        s[ind] = '0';
        findValidNum(s, st, result, ind+1);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        unordered_set<string>st;

        for (auto &num : nums) {
            st.insert(num);
        }
        string s(n, '0');
        string result = "";
        findValidNum(s, st, result, 0);
        return result;
    }
};