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
    void shiftBranch(TreeNode* node){
        TreeNode* branch=node->right;
        node=node->left;
        while(node->right) node=node->right;
        node->right=branch;
    }
    TreeNode* modify(TreeNode* node){
        if(!node->left) return node->right;
        else if(!node->right) return node->left;
        else {
            shiftBranch(node);
            return node->left;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        TreeNode* node=root;
        if(node->val==key){
            return modify(node);
        }
        while(node){
            if(node->val>key){
                if(node->left && node->left->val==key){
                    node->left=modify(node->left);
                    break;
                }
                else node=node->left;
            }
            else if(node->val<key){
                if(node->right && node->right->val==key){
                    node->right=modify(node->right);
                    break;
                }
                else node=node->right;
            }
        }
        return root;
    }
};