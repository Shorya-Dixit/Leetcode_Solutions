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
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, unordered_map<int,int>& inMap, int postStart, int postEnd, int inStart, int inEnd){
        if(postStart>postEnd || inStart>inEnd) return NULL;
        TreeNode* root= new TreeNode(postorder[postEnd]);
        int inRoot= inMap[root->val];
        int numsleft= inRoot-inStart;
        root->left= build(postorder,inorder,inMap,postStart,postStart+numsleft-1,inStart,inRoot-1);
        root->right= build(postorder,inorder,inMap,postStart+numsleft,postEnd-1,inRoot+1,inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>inMap;
        for(int i=0;i<inorder.size();i++) inMap[inorder[i]]=i;
        TreeNode* root= build(postorder,inorder,inMap,0,postorder.size()-1,0,inorder.size()-1);
        return root; 
    }
};