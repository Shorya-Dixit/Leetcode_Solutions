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
    void markParents(TreeNode* root,TreeNode* previous, unordered_map<TreeNode*,TreeNode*>&parent){
        if(!root) return;
        parent[root]=previous;
        markParents(root->left,root,parent);
        markParents(root->right,root,parent);
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        markParents(root,NULL,parent);
        unordered_map<TreeNode*,bool>visited;
        queue<pair<TreeNode*,int>>q;
        vector<int>ans;
        q.push({target,0});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int dist=q.front().second;
            visited[node]=true;
            if(dist==k) ans.push_back(node->val);
            q.pop();
            if(parent[node] && dist+1<=k && !visited[parent[node]]) q.push({parent[node],dist+1});
            if(node->left && dist+1<=k && !visited[node->left]) q.push({node->left,dist+1});
            if(node->right && dist+1<=k && !visited[node->right]) q.push({node->right,dist+1});
        }
        return ans;
    }
};