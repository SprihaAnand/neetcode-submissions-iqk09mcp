class Solution {
public:
    void help(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, vector<bool>& taken){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        //take
        for(int i=0; i<nums.size(); i++){
            if(!taken[i]){
                temp.push_back(nums[i]);
                taken[i] = true;
                help(nums, ans, temp, taken);
                temp.pop_back();
                taken[i]=false;
            } else{
                continue;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<bool> taken(n, false);
        vector<int> temp;
        help(nums, ans, temp, taken);
        return ans;
    }
};
