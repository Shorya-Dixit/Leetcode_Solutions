class Solution {
public:
    int cost(vector<int>& cuts, int i, int j, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int cut=i;cut<=j;cut++){
            int x=(cuts[j+1]-cuts[i-1])+cost(cuts,i,cut-1,dp)+cost(cuts,cut+1,j,dp);
            ans=min(ans,x);
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
        return cost(cuts,1,cuts.size()-2,dp);
    }
};