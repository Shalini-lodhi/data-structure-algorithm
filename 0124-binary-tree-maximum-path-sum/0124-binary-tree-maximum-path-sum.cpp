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
     int maxSum = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = max(dfs(root->left), 0);  // Ignore negative sums
        int right = max(dfs(root->right), 0);

        int localMax = root->val + left + right;  // Path through current node
        maxSum = max(maxSum, localMax);  // Update global max

        return root->val + max(left, right);  // Return max single path sum
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};