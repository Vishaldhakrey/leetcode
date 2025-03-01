class Solution {
public:
    int findAllPaths(vector<vector<int>>& dp, int row, int col) {
        if (row == 0 && col == 0) {
            return 1;
        }
        if (row < 0 || col < 0) {
            return 0;
        }
        if (dp[row][col] != -1) return dp[row][col];
        int up = findAllPaths(dp, row-1, col);
        int left = findAllPaths(dp, row, col-1);
        dp[row][col] = up + left;
        return up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return findAllPaths(dp, m-1, n-1);
    }
};