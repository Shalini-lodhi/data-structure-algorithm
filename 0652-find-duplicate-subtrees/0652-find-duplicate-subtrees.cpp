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
    unordered_map<string, int> subtreeMap;
    vector<TreeNode*> result;

    string serialize(TreeNode* root) {
        if (!root)
            return "#";

        string left = serialize(root->left);
        string right = serialize(root->right);
        string subtree = to_string(root->val) + "," + left + "," + right;

        if (subtreeMap[subtree] == 1) {
            result.push_back(root);
        }
        subtreeMap[subtree]++;
        return subtree;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return result;
    }
};