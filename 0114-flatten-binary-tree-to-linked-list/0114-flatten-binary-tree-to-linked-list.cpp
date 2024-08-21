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
    // Initialize a global variable
    // 'prev' to keep track of the
    // previously processed node.
    TreeNode* prev = NULL;

    // Function to flatten a binary tree
    // to a right next Linked List structure
    void flatten(TreeNode* root) {
       // Base case: If the current
       // node is NULL, return.
       if(root==NULL){
           return;
       }

       // Recursive call to
       // flatten the right subtree
       flatten(root->right);
       
       // Recursive call to
       // flatten the left subtree
       flatten(root->left);
       
       // At this point, both left and right
       // subtrees are flattened, and 'prev'
       // is pointing to the rightmost node
       // in the flattened right subtree.

       // Set the right child of
       // the current node to 'prev'.
       root->right = prev;

       // Set the left child of the
       // current node to NULL.
       root->left = NULL;

       // Update 'prev' to the current
       // node for the next iteration.
       prev = root;
    }
};