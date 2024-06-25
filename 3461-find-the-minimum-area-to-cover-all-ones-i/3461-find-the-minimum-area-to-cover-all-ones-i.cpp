class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int hs=INT_MAX,he=0;
        int vs=INT_MAX,ve=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    hs=min(hs,i);
                    vs=min(vs,j);
                    he=max(he,i);
                    ve=max(ve,j);
                }
            }
        }
        return (he-hs+1)*(ve-vs+1);
    }
};