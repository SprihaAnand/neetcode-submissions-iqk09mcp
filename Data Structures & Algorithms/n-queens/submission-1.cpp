class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, true);
        vector<bool> d1(2*n-1, true);
        vector<bool> d2(2*n-1, true);
        backtrack(0, board, res, col, d1, d2);
        return res;
    }
    void backtrack(int r, vector<string>& board, vector<vector<string>>& res, vector<bool>& col,vector<bool>&d1, vector<bool>& d2){
        if(r==board.size()){
            res.push_back(board);
            return;
        }
        int n = board.size();
        for(int c=0; c<n; c++){
            if(col[c] && d1[r-c+ n - 1] && d2[r+c]){
                board[r][c] = 'Q';
                col[c] = false;
                d1[r-c+n-1] =false;
                d2[r+c]=false;
                backtrack(r+1, board, res, col, d1, d2);
                board[r][c] = '.';
                col[c] = true;
                d1[r-c+n-1] =true;
                d2[r+c]=true;
            }
        }
    }
    bool isSafe(int r, int c, vector<string>& board){
        for(int i=0; i<r; i++){
            if(board[i][c]=='Q') return false;
        }
        for(int i = r-1, j = c-1; i>=0 &&j>=0; i--,j--){
            if(board[i][j]=='Q') return false;
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
};