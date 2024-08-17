/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getPath(TreeNode* node, TreeNode* dest, vector<TreeNode*>& path, int& flag){
        path.push_back(node);
        if (node->val==dest->val) {
            flag=1;
            return;
        } 
        if (flag==0 && node->left) {
            getPath(node->left, dest, path, flag);
            if(flag==0) path.pop_back(); // backtrack
        }
        if (flag==0 && node->right) {
            getPath(node->right, dest, path, flag);
            if(flag==0) path.pop_back(); // backtrack
        }
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>pathp;
        vector<TreeNode*>pathq;
        int flag=0;
        getPath(root,p,pathp,flag);
        flag=0;
        getPath(root,q,pathq,flag);
        TreeNode* ans=root;
        for(int i=1;i<min(pathq.size(),pathp.size());i++){
            if(pathp[i]->val==pathq[i]->val) ans=pathp[i];
        }
        return ans;
    }
};