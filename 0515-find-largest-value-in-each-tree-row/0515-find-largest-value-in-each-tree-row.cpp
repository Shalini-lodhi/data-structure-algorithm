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
    void bfs(TreeNode* root, vector<int>& res){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int lvlsz = q.size();
            int maxVal = INT_MIN; 

            for(int l = 0; l < lvlsz; ++l){
                TreeNode* node = q.front();
                q.pop();
                maxVal = max(maxVal, node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(maxVal);
        }
    }
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        bfs(root, res);
        return res;
    }
};