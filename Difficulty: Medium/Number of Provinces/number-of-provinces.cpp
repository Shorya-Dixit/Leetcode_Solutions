//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>> &adj,int V,int node,vector<int>&vis){
        for(int i=0;i<V;i++){
            if(adj[node][i]==1 && vis[i]!=1) {
                vis[i]=1;
                dfs(adj,V,i,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>vis(V,0);
        int count=0;
        for(int j=0;j<V;j++){
            if(!vis[j]){
                vis[j]=1;
                dfs(adj,V,j,vis);
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends