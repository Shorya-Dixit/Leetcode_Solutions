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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& inMap, int preStart, int preEnd, int inStart, int inEnd){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode* root= new TreeNode(preorder[preStart]);
        int inRoot= inMap[root->val];
        int numsleft= inRoot-inStart;
        root->left= build(preorder,inorder,inMap,preStart+1,preStart+numsleft,inStart,inRoot-1);
        root->right= build(preorder,inorder,inMap,preStart+1+numsleft,preEnd,inRoot+1,inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inMap;
        for(int i=0;i<inorder.size();i++) inMap[inorder[i]]=i;
        TreeNode* root= build(preorder,inorder,inMap,0,preorder.size()-1,0,inorder.size()-1);
        return root; 
    }
};