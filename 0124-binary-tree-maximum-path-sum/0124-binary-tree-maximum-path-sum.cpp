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
    int maxSum(TreeNode* node,int &maxP){
        if(node==NULL) return 0;
        int ls=max(0,maxSum(node->left,maxP));
        int rs=max(0,maxSum(node->right,maxP));
        maxP=max(ls+rs+node->val,maxP);
        return node->val+max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        int maxP=INT_MIN;
        maxSum(root,maxP);
        return maxP;
    }
};
// its is exactly the same as maximum path length(diameter)
// if you replace node->val by 1 in return and remove node->val in maxP and remove max in ls,rs.
// it will give maximum diameter.