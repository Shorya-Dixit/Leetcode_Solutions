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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        map<int,int> mp;
        queue<pair<TreeNode*, int>> todo;
        todo.push({root,0});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode* temp = p.first;
            int y = p.second;  
            if(mp.find(y)==mp.end())mp[y]=temp->val;
            if(temp->right){
                todo.push({temp->right,y+1});
            }
            if(temp->left){
                todo.push({temp->left,y+1});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};