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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        int ans = INT_MIN;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int h = q.front().second;
            ans = max(ans, h);
            q.pop();
            if(node->left) q.push(make_pair(node->left, h+1));
            if(node->right) q.push(make_pair(node->right, h+1));
        }
        return ans;
    }
};