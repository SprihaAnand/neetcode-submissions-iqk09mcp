/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(vector<vector<int>>& ans, TreeNode* root, int level){
        if(!root) return;
        if(ans.size()==level)
            ans.push_back(vector<int>());
        ans[level].push_back(root->val);
        if(root->left)dfs(ans, root->left, level+1);
        if(root->right)dfs(ans, root->right, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(ans, root,0);
        vector<int> rsv;
        for(auto it: ans){
            rsv.push_back(it.back());
        }
        return rsv;
    }
};