class Solution {
public:
    TreeNode* help(vector<int>& po, vector<int>& io, int pl, int pr, int il, int ir, map<int, int>& iomap){
        if(il > ir || pl > pr) return nullptr;
        TreeNode* root = new TreeNode(po[pl]);
        int rootIdx = iomap[po[pl]];
        int numsLeft = rootIdx - il;
        root->left = help(po, io, pl + 1, pl + numsLeft, il, rootIdx - 1, iomap);
        root->right = help(po, io, pl + numsLeft + 1, pr, rootIdx + 1, ir, iomap);
        return root;
    }
    TreeNode* buildTree(vector<int>& po, vector<int>& io) {
        int n = po.size();
        map<int, int> iomap;
        for(int i = 0; i < n; i++){
            iomap[io[i]] = i;
        }
        return help(po, io, 0, n - 1, 0, n - 1, iomap);
    }
};