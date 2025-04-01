class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();

        vector<bool>seen(26, false);

        vector<int>lastIdx(26, 0);
        for (int i=0; i<n; i++) {
            lastIdx[s[i] - 'a'] = i;
        }

        stack<char>st;  //monotonic stack

        for (int i=0; i<n; i++) {
            char ch = s[i];

            if (seen[ch - 'a'] == true) {
                continue;
            }

            while (!st.empty() && st.top() > ch && lastIdx[st.top() - 'a'] > i) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            seen[ch - 'a'] = true;
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