//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(vector<int> adj[],vector<int>&vis,stack<int>&st,int node){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]) dfs(adj,vis,st,it);
	    }
	    st.push(node);
	    return;
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{   
	    vector<int>vis(V,0);
	    vector<int>ans;
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]) dfs(adj,vis,st,i);
	    }
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
//If we will print nodes in descending order of their 
//finishing time of dfs that will be a topo sort.

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends