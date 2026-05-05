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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        queue<pair<TreeNode*, pair<long long,long long>>> q;
        q.push(make_pair(root, make_pair(LLONG_MIN, LLONG_MAX)));
        while(!q.empty()){
            TreeNode* node = q.front().first;
            long long left = q.front().second.first;
            long long right = q.front().second.second;
            q.pop();
            if(node->val<=left || node->val>=right) return false;
            if(node->left) {
                q.push(make_pair(node->left, make_pair(left, node->val)));
            }
            if(node->right){
                q.push(make_pair(node->right, make_pair(node->val, right)));
            }
        }
        return true;
    }
};