class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";

        string ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                ans += "#,";
                continue;
            }

            ans += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }

        return ans;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        vector<string> tokens;
        string token;
        stringstream ss(data);

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.empty() || tokens[0] == "#") return NULL;

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < tokens.size()) {
            TreeNode* node = q.front();
            q.pop();

            if (i < tokens.size() && tokens[i] != "#") {
                node->left = new TreeNode(stoi(tokens[i]));
                q.push(node->left);
            }
            i++;

            if (i < tokens.size() && tokens[i] != "#") {
                node->right = new TreeNode(stoi(tokens[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};