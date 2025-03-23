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
/*
root = [3,9,20,null,null,15,7] -> Inorder Traversal

*/

class Solution {
public:
    void bfs(TreeNode* root, vector<vector<int>>& output) {
        if (!root)
            return;

        map<int, vector<pair<int, int>>> nodes;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}}); // Root starts at (0,0)

        while (!q.empty()) {
            auto [node, position] = q.front();
            q.pop();
            int row = position.first, col = position.second;

            // Insert node value into map[column]
            nodes[col].push_back({row, node->val});

            // Process left and right children
            if (node->left)
                q.push({node->left, {row + 1, col - 1}});
            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }

        for (auto& [col, vec] : nodes) {
            // Sort nodes by row first, then value
            sort(vec.begin(), vec.end());

            // Extract sorted values
            vector<int> sorted_column;
            for (auto& [row, value] : vec)
                sorted_column.push_back(value);

            output.push_back(sorted_column);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> output;
        bfs(root, output);
        return output;
    }
};