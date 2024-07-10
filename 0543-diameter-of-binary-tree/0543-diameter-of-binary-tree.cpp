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
    int maxDia(TreeNode* node,int &maxd){
        if(node==NULL) return 0;
        int lh=maxDia(node->left,maxd);
        int rh=maxDia(node->right,maxd);
        maxd=max(lh+rh,maxd);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxd=0;
        maxDia(root,maxd);
        return maxd;
    }
};