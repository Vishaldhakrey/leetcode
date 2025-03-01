class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, vector<int>>um;
        //Storing the vector in map to there respective index
        for (int r=0; r<m; r++ ){
            for (int c=0; c<n; c++) {
                um[r-c].push_back(mat[r][c]);
            }
        }
        //sorting the the vector in map
        for (auto &vec : um) {
            sort(begin(vec.second), end(vec.second));
        }

        //back to the diagonal from end that will help to reduce time complexity because in front everytime element move to left
        for (int r=m-1; r>=0; r--) {
            for (int c=n-1; c>=0; c--) {
                mat[r][c] = um[r-c].back();
                um[r-c].pop_back();
            }
        }
        return mat;
    }
};