class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>&ans,vector<int>&path,int node){
        if(node==graph.size()-1) {
            ans.push_back(path);
            return;
        }
        for(auto it:graph[node]){
            path.push_back(it);
            dfs(graph,ans,path,it);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>path;
        path.push_back(0);
        dfs(graph,ans,path,0);
        return ans;
    }
};