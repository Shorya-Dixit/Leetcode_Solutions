class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1);
        int ans=1;
        for(int i=1;i<arr.size();i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]) dp[i]=max(dp[i],1+dp[j]);
                ans=max(ans,dp[i]);
            }
        }
        return ans;
    }
};
// dp[i] represents length of longest subsequence which ends at arr[i]
// check out previous submissions too