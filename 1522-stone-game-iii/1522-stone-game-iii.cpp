class Solution {
public:
    int game(vector<int>& stoneValue, vector<int>& suffixSum, int i, vector<int>&dp){
        if(i>=stoneValue.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MIN;
        for(int x=1; x<=3 ;x++){
            ans=max(ans,suffixSum[i]-game(stoneValue,suffixSum,i+x,dp));
        }
        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size(),-1);
        vector<int>suffixSum(stoneValue.size());
        suffixSum[stoneValue.size()-1]=stoneValue[stoneValue.size()-1];
        for(int i=stoneValue.size()-2;i>=0;i--) suffixSum[i]=stoneValue[i]+suffixSum[i+1];
        int alice=game(stoneValue,suffixSum,0,dp);
        cout<<alice;
        if(alice==suffixSum[0]-alice) return "Tie";
        if(alice>suffixSum[0]-alice) return "Alice";
        else return "Bob";
    }
};