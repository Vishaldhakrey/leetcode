class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for (int r=0; r<n; r++) {
            for (int c=r; c<m; c++) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }
        for (int r=0; r<n; r++) {
            reverse(matrix[r].begin(), matrix[r].end());
        }
    }
};