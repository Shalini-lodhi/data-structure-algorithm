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
    void bfs(TreeNode* root, vector<vector<int>>& output){
        if(!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int ls = q.size();
            vector<int> currL;

            for(int l = 0; l < ls; ++l){
                TreeNode* n = q.front();
                q.pop();
                currL.push_back(n->val);

                if(n-> left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            output.push_back(currL);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        bfs(root, output);
        return output;
    }
};