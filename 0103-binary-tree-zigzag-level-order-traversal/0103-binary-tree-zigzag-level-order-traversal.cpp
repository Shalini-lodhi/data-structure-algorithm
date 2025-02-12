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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        // Base case: If the tree is empty
        if (!root)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true; // Flag to alternate the direction

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            vector<int> levelNodes;

            // Process each node in the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                levelNodes.push_back(node->val);

                // Add the children of the current node to the queue
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // If we are going right to left, reverse the levelNodes
            if (!leftToRight) {
                reverse(levelNodes.begin(), levelNodes.end());
            }

            result.push_back(levelNodes);

            // Toggle the direction for the next level
            leftToRight = !leftToRight;
        }

        return result;
    }
};