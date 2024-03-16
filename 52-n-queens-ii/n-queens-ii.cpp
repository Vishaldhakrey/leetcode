class Solution {

    bool isSafe(int row, int col, int n, vector<string>&board){
        int dr = row;
        int dc = col;

        while(row>=0 && col>=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }
        row = dr;
        col = dc;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        row = dr;
        col = dc;
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
            row++;
        }
        return true;
    }
    
    int solve(int col, int n, vector<string>&board){
        int count = 0;
        if(col == n){
            return 1;
        }
        for(int row=0; row<n; row++){
           if (isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                count += solve(col + 1, n, board);
                board[row][col] = '.';
            }
        }
        return count;
    }
public:
    int totalNQueens(int n) {
        vector<string>board(n, string(n, '.'));
        
        return solve(0, n, board);
    }
};