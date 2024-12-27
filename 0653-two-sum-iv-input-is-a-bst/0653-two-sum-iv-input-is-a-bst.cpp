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
    bool present(TreeNode* root,int r){
        if(!root) return false;
        if(root->val==r) return true;
        else if(root->val>r) return present(root->left,r);
        else return present(root->right,r);
    }
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            int val=node->val;
            int rem=k-val;
            q.pop();
            if(val!=rem && present(root,rem)) return true;
            else{
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return false;
    }
};