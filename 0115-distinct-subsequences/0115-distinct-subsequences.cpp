class Solution {
public:
    int count(string &s, string &t, int i, int j, vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=count(s,t,i-1,j-1,dp)+count(s,t,i-1,j,dp);
        }
        else return dp[i][j]=count(s,t,i-1,j,dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return count(s,t,s.size()-1,t.size()-1,dp);
    }
};
// here dp[i][j] represents the no. of distinct subsequences of s[0 to i] which equals t[0 to j]. 