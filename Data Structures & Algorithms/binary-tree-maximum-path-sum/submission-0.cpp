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
    int ans = INT_MIN;
    int sum(TreeNode* root){
        if(!root) return 0;
        int left = sum(root->left);
        int right = sum(root->right);
        int curr_max_sum = root->val +max(0, left)+max(0,right);
        ans = max(ans, curr_max_sum);
        return root->val+max(left,max(right,0));
    }
    int maxPathSum(TreeNode* root) {
        sum(root);
        return ans;
    }
};