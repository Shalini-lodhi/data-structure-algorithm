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
    /*
    #1. DFS - recursive - queue
    #2. BFS - iterative - stack
    #3. Morris - without extra space
    */
    // DFS
    void dfs(TreeNode* root, vector<int>& output) {
        if (root == nullptr)
            return;
        dfs(root->left, output);
        output.push_back(root->val);
        dfs(root->right, output);
    }
    // ierative
    void ierative(TreeNode* root, vector<int>& output) {
        stack<TreeNode*> st;
        TreeNode* current = root;

        while (current != nullptr || !st.empty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            output.push_back(current->val);
            current = current->right;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        // dfs(root, output);
        ierative(root, output);
        return output;
    }
};