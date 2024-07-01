class Solution {
public:
    void dfs(vector<vector<int>>&ans,vector<vector<int>>&adj,int node,int ancestor,vector<int>&vis){
        vis[ancestor]=1;
        for(int j=0;j<adj[ancestor].size();j++){
            if(!vis[adj[ancestor][j]]){
                ans[node].push_back(adj[ancestor][j]);
                dfs(ans,adj,node,adj[ancestor][j],vis);
            }
        }
        return;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<vector<int>>ans(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            dfs(ans,adj,i,i,vis);
        }
        for (int i = 0; i < n; ++i) {
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};