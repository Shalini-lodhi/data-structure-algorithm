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
    int getMinimumDifference(TreeNode* root) {
        // Initialize the previous node as a pointer to NULL
        TreeNode* prev = nullptr;
        int minDiff = INT_MAX;

        // Helper function to perform in-order traversal
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node)
                return; // Base case: if node is null, return

            inorder(node->left); // Traverse left subtree

            // If the previous node is not null, calculate the difference
            if (prev != nullptr) {
                minDiff = min(minDiff, abs(node->val - prev->val));
            }

            // Update previous node to current node
            prev = node;

            inorder(node->right); // Traverse right subtree
        };

        inorder(root); // Start in-order traversal from root

        return minDiff; // Return the minimum difference found
    }
};