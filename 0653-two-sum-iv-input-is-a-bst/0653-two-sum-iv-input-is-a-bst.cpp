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
    void getInorder(TreeNode* root,vector<int>&v){
        if(!root) return;
        getInorder(root->left,v);
        v.push_back(root->val);
        getInorder(root->right,v);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        getInorder(root,v);
        int left=0,right=v.size()-1;
        while(left<right){
            int sum=v[left]+v[right];
            if(sum==k) return true;
            else if(sum>k) right--;
            else if(sum<k) left++;
        }
        return false;
    }
};