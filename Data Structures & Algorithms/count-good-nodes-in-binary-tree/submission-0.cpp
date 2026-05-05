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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        int ans = 0;
        if(!root) return 0;
        q.push(make_pair(root, root->val));
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int curr_max = q.front().second;
            q.pop();
            if(curr_max<=node->val) ans++;
            if(node->left) q.push(make_pair(node->left, max(curr_max, node->val)));
            if(node->right) q.push(make_pair(node->right, max(curr_max, node->val)));
        }
        return ans;
    }
};