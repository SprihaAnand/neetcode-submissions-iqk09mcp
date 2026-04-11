class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // encode each (i,j) to one number
        //cell number = i*n + j
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m*n-1;
        while(l<=r){
            int mid = (r-l)/2+l;
            int i = mid/n;
            int j = mid%n;
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) r = mid-1;
            else l = mid+1;
        }
        return false;
    }
};