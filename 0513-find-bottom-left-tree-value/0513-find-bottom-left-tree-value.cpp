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
/*
- (preorder) root = [2,1,3]
*/

class Solution {
public:
    int bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int lmn = root->val;

        while(!q.empty()){
            int lvlsz = q.size();
            lmn = q.front()->val; 

            for(int l = 0; l < lvlsz; ++l){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return lmn;
    }
    int findBottomLeftValue(TreeNode* root) {
        return bfs(root);
    }
};