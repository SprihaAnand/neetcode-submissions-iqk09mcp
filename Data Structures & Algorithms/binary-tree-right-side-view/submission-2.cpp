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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(!root) return ans;
        int curr=0;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* node = q.front();
                if(ans.size()==curr) ans.push_back(-1);
                ans[curr]=node->val;
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            curr++;
        }
        return ans;
    }
};