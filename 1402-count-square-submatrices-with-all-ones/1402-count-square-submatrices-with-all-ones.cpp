class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size()));
        int count=0;
        for(int i=0;i<matrix.size();i++) {
            dp[i][0]=matrix[i][0];
            count+=dp[i][0];
        }
        for(int j=1;j<matrix[0].size();j++) { // j starts from 1 as dp[0][0] has already been considered.
            dp[0][j]=matrix[0][j];
            count+=dp[0][j];
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==1){
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    count+=dp[i][j];
                }
                else dp[i][j]=0;
            }
        }
        return count;
    }
};