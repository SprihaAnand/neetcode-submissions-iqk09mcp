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
        stack<pair<TreeNode*, int>> st;
        st.push(make_pair(root, 1));
        int ans = INT_MIN;
        while(!st.empty()){
            TreeNode* node = st.top().first;
            int h = st.top().second;
            ans = max(ans, h);
            st.pop();
            if(node->left) st.push(make_pair(node->left, h+1));
            if(node->right) st.push(make_pair(node->right, h+1));
        }
        return ans;
    }
};