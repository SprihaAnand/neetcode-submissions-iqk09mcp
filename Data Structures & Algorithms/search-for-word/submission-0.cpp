class Solution {
public:
    bool dfs(int r, int c, vector<vector<char>>& board, string word,int m, int n, string temp,vector<vector<bool>>& vis){
        if(temp.size()>word.size()) return false;
        temp.push_back(board[r][c]);
        vis[r][c]=true;
        if(temp==word) {
            return true;
        }
        vector<int> dr = {1,0,-1,0};
        vector<int> dc = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc]){
                if (dfs(nr, nc, board, word, m, n, temp, vis)) return true;
            }
        }
        temp.pop_back();
        vis[r][c] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        string temp = "";
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int r = 0; r<m; r++){
            for(int c = 0; c<n; c++){
                if(dfs(r, c, board, word,m,n, temp, vis)) return true;
            }
        }
        return false;
    }
};