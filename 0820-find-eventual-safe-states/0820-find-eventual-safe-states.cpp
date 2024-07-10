class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int node,vector<int>&vis,vector<int>&pathvis,vector<int>&check){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(graph,it,vis,pathvis,check)) {check[node]=0;return true;}
            }
            else if(pathvis[it]) {check[node]=0;return true;}
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        vector<int>check(V,0);
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(graph,i,vis,pathvis,check);
        }
        for(int i=0;i<V;i++){
            if(check[i]) ans.push_back(i);
        }
        return ans;
    }
};
//if a node is a part of a cicle, its not safe