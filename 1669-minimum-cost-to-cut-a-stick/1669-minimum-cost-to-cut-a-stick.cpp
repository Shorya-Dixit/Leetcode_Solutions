class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),0));
        for(int i=cuts.size()-1;i>=1;i--){
            for(int j=i;j<cuts.size()-1;j++){
                int ans=INT_MAX;
                for(int cut=i;cut<=j;cut++){
                    int x=(cuts[j+1]-cuts[i-1])+dp[i][cut-1]+dp[cut+1][j];
                    ans=min(ans,x);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][cuts.size()-2];
    }
};