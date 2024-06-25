class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int node,int s,vector<int>&set)
    {   
        set[node]=s;
        for(auto it: graph[node]){
            if(set[it]==-1){
                if(!dfs(graph,it,!s,set)) return false;
            }
            else{
                if(set[it]==s) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>set(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(set[i]==-1){
                if(!dfs(graph,i,0,set)) return false;
            }
        }
        return true;
    }
};
// representing A,B set by 0,1.