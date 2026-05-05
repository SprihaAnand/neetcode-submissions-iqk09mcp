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
    void help(TreeNode* root, vector<int>& iot){
        if(!root) return;
        help(root->left, iot);
        iot.push_back(root->val);
        help(root->right, iot);
    }
    int kthSmallest(TreeNode* root, int k) {
        //in order traversal will be a sorted list
        if(!root) return 0;
        vector<int> iot;
        help(root, iot);
        return iot[k-1]; 
    }
};