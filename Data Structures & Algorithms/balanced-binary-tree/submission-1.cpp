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
    int h(TreeNode* root){
        if(!root) return 0;
        else if(!root->left && !root->right) return 1;
        return 1+max(h(root->right), h(root->left));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(abs(h(temp->left)-h(temp->right))>1) return false;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        
        return true;
    }
};
