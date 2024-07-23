class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        q.push({0,{0,0}});
        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            int rows[]={1,1,1,0,0,-1,-1,-1};
            int cols[]={1,0,-1,1,-1,1,0,-1};
            for(int i=0;i<=7;i++){
                int r=row+rows[i];
                int c=col+cols[i];
                if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==0 && dis+1<dist[r][c]){
                    dist[r][c]=1+dis;
                    q.push({dist[r][c],{r,c}});
                }
            }
        }
        cout<<dist[n-1][n-1];
        return dist[n-1][n-1]==INT_MAX?-1:dist[n-1][n-1]+1;
    }
};