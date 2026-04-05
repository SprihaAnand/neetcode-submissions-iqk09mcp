class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // check rows
        for(int i = 0; i < 9; i++) {
            int num = 0;
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int ind = board[i][j]-1-'0';
                if(num & (1 << ind)) return false;
                num = num | (1 << ind);
            }
        }

        // check columns
        for(int j = 0; j < 9; j++) {
            int num = 0;
            for(int i = 0; i < 9; i++) {
                if(board[i][j] == '.') continue;
                int ind = board[i][j]-1-'0';
                if(num & (1<< ind)) return false;
                num = num | (1<<ind);
            }
        }

        // check 3x3 subgrids
        vector<int> nums(9,0);
        for(int i = 0; i < 9; i++) { 
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int c = (i / 3) * 3 + (j / 3);
                int ind = board[i][j]-1-'0';

                if(nums[c] & (1<<ind)) return false;

                nums[c] = nums[c] | (1<<ind);
            }
        }
            

        return true;
    }
};