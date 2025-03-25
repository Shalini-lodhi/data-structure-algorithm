/*
inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]


*/
class Solution {
public:
    unordered_map<int, int> inorderIndexMap;
    int postIndex;

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder,
                              int inStart, int inEnd) {
        if (inStart > inEnd)
            return NULL;

        // Pick current root from postorder
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Find position of root in inorder
        int inIndex = inorderIndexMap[rootVal];

        // Build right subtree first (since postorder processes right before
        // left)
        root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd);
        root->left = buildTreeHelper(inorder, postorder, inStart, inIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;

        // Store inorder indices for quick lookup
        for (int i = 0; i < inorder.size(); i++)
            inorderIndexMap[inorder[i]] = i;

        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1);
    }
};