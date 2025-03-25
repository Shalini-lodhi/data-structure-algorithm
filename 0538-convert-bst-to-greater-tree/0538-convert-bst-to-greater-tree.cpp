/*
#1. Inorder Traversal + replace the value with prefix sum
    - inorder traversal and store all the value in array
    - compute the preiix sums and update each node value 
    - traverse the tree again to replace the node value

    root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
    inorder traversal = [null, 0, null , 1, null, 2, 3, 4, null, 5, null, 6, null, 7, 8]
    update with prefix sum = [null, 36, null, 36, null, 35, 33, 30, null, 26, 21, null, 15, 8]
    preorder traversal = [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

    TC: O(N logN)
        - sorting: O(N logN)
        - tree taversal O(N)
    SC: O(N)

#2. Reverse Inorder Traversal + Global Variable
    - global varibale = 0: store the cumulative sum
    - reverse inorder traversal: right -> node -> left
    - update each node's value by adding the cumulative sun to it and update the "sum"
    - recursively process the left sub-tree

    --x--
    sum | node  | update sum
     0  |   8   |   8
     8  |   7   |   15
     15 |   6   |   21
     21 |   5   |   26
     ...
     ...
     36 |   0   |   36

    --x--
    TC: O(N) - since we are visiting every node once
    SC: O(N) or O(H) - H is height of tree
              

*/
class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        
        // Reverse inorder traversal: Right -> Node -> Left
        convertBST(root->right);
        
        // Update current node
        sum += root->val;
        root->val = sum;
        
        convertBST(root->left);
        
        return root;
    }
};