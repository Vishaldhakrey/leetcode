class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int>result;

        for (int diag=0; diag < (m+n-1); diag++) {
            //bottom to Top
            if (diag%2 == 0) {
                int row = min(diag, m-1);
                int col = (diag - row);

                while (row >= 0 && col < n) {
                    result.push_back(mat[row][col]);
                    row--;
                    col++;
                }
            }
            // Top to bottom
            else {
                int col = min(diag, n-1);
                int row = (diag - col);

                while (col >= 0 && row < m) {
                    result.push_back(mat[row][col]);
                    col--;
                    row++;
                }
            }
        }
        return result;
    }
};