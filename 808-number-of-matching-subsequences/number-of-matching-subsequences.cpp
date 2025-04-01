class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n   = s.size();
        int cnt = 0;
        
        map<char, vector<int>>mp;

        for (int i=0; i<n; i++) {
            char ch = s[i];
            mp[ch].push_back(i);
        }

        for (auto &word : words) {
            int pivotIdx = -1;
            bool isSubsequence = true;

            for (auto &ch : word) {
                if (mp.find(ch) == mp.end()) {
                    isSubsequence = false;
                    break;
                }

                auto it = upper_bound(mp[ch].begin(), mp[ch].end(), pivotIdx);
                if (it == mp[ch].end()) { //out of bound
                    isSubsequence = false;
                    break;
                }
                pivotIdx = *it;
            }

            if (isSubsequence == true) {
                cnt++;
            }
        }
        return cnt;
    }
};