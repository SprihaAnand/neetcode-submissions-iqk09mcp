class Solution {
public:
    bool dfs(int r, int c, vector<vector<char>>& board, string word,int idx){
        int m = board.size();
        int n = board[0].size();
        if(idx==word.size()) return true;
        if(r<0 || r>=m || c<0 || c>=n || word[idx]!=board[r][c]) return false;
        char orig = board[r][c];
        board[r][c] = '#';
        bool poss = dfs(r+1,c,board,word,idx+1)||
                    dfs(r-1,c,board,word,idx+1)||
                    dfs(r,c+1,board,word,idx+1)||
                    dfs(r,c-1,board,word,idx+1);
        board[r][c] = orig;
        return poss;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int r = 0; r<m; r++){
            for(int c = 0; c<n; c++){
                if(word[0]==board[r][c] && dfs(r, c, board, word, 0)) return true;
            }
        }
        return false;
    }
};