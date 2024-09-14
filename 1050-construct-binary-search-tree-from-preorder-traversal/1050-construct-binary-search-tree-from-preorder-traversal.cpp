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
    TreeNode* construct(vector<int>& preorder,int& ind,int lim){
        if(ind==preorder.size() || preorder[ind]>lim) return NULL;
        TreeNode* root=new TreeNode(preorder[ind]);
        ind++;
        root->left=construct(preorder,ind,root->val);
        root->right=construct(preorder,ind,lim);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int lim=INT_MAX;
        int ind=0;
        return construct(preorder,ind,lim);
    }
};