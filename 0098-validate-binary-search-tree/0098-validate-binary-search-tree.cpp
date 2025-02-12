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
    bool isValidBSTUtil(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (!root)
            return true;

        if ((minNode && root->val <= minNode->val) ||
            (maxNode && root->val >= maxNode->val)) {
            return false;
        }

        return isValidBSTUtil(root->left, minNode, root) &&
               isValidBSTUtil(root->right, root, maxNode);
    }
    bool isValidBST(TreeNode* root) { return isValidBSTUtil(root, NULL, NULL); }
};