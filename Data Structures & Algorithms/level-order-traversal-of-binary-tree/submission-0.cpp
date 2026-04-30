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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> curr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            curr.clear();
            queue<TreeNode*> hq;

            while(!q.empty()){
                TreeNode* node = q.front();
                curr.push_back(node->val);
                q.pop();
                if(node->left) {
                    hq.push(node->left);
                }
                if(node->right) {
                    hq.push(node->right);
                }
            }
            ans.push_back(curr);
            q = hq;

        }
        return ans;
    }
};