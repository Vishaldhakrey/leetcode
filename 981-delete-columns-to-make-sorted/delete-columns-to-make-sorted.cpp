class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        int cnt = 0;
        for (int c=0; c<n; c++) {
            for (int r=1; r<m; r++) {
                if (strs[r][c] < strs[r-1][c]) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};