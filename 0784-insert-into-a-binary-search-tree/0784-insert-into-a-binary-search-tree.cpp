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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return root=new TreeNode(val);
        TreeNode* node=root;
        while(node){
            if(node->right && node->val<val) node=node->right;
            else if(node->left && node->val>val) node=node->left;
            else break;
        }
        if(node->val<val) node->right=new TreeNode(val);
        else if(node->val>val) node->left=new TreeNode(val);
        return root;
    }
};