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
    int solve(TreeNode* root, int &res){
    if(root==NULL)
        return 0;
   
    int L=solve(root->left, res);
    int R=solve(root->right, res);
    
    int temp = max(R, L)+1;
    int ans =max(temp,(1+R+L));
    res= max(res, ans);
    
    return temp;
    }
    int diameterOfBinaryTree(TreeNode* root)
    {
    int res=INT_MIN;
    solve(root, res);
    return res-1;
    }
};