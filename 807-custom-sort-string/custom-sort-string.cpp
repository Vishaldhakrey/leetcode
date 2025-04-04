class Solution {
public:
    string customSortString(string order, string s) {
        int n = order.size();
        vector<int> indices(26, 0);

        for (int i=0; i<n; i++) {
            indices[order[i] - 'a'] = i;
        }

        auto myComparator = [&indices] (auto &ch1, auto &ch2) {
            return indices[ch1-'a'] < indices[ch2 - 'a'];
        };
        sort(s.begin(), s.end(), myComparator);

        return s;
    }
};
