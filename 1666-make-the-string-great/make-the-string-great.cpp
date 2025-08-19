class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        stack<char>st;
        int j=0;
        while(j<s.size()) {
            if (!st.empty() && toupper(st.top()) == toupper(s[j]) && st.top() != s[j]) {
                st.pop();
            }
            else {
                st.push(s[j]);
            }
            j++;
        }
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};