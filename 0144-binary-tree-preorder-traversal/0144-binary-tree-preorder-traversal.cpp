/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // DFS
    void dfs(TreeNode* root, vector<int>& output) {
        if (root == nullptr)
            return;
        output.push_back(root->val);
        dfs(root->left, output);
        dfs(root->right, output);
    }
    // ierative
    void ierative(TreeNode* root, vector<int>& output) {
        if (root == NULL)
            return;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            output.push_back(node->val);

            if (node->right)
                st.push(node->right); // Push right child first
            if (node->left)
                st.push(node->left); // Then push left child
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        // dfs(root, output);
        ierative(root, output);
        return output;
    }
};