class Solution {
public:
// check previous submissions too
// this one is done using morris traversal
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                // If yes, find the rightmost
                // node in the left subtree
                TreeNode* pre = curr->left;
                while (pre->right) {
                    pre = pre->right;
                }
                // Connect the rightmost node in
                // the left subtree to the current
               //  node's right child
                pre->right = curr->right;
                // Move the entire left subtree to the
                // right child of the current node
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};