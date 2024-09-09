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
    bool check(TreeNode* node, long min, long max){
        if(!node) return true;
        if(node->val>=max || node->val<=min) return false;
        return check(node->left,min,node->val) && check(node->right,node->val,max);
    }
    bool isValidBST(TreeNode* root) {
        long min=LONG_MIN,max=LONG_MAX;
        return check(root,min,max);
    }
};