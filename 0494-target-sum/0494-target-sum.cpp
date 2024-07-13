class Solution {
public:
    int count(vector<int>& arr,int tsum, int s1,int d, int i,vector<vector<int>>&dp){
        if(i<0){
            if(2*s1==tsum+d) return 1;
            else return 0;
        }
        if(dp[i][s1]!=-1) return dp[i][s1];
        int nottake=count(arr,tsum,s1,d,i-1,dp);
        int take=0;
        if(2*(arr[i]+s1)<=tsum+d) take=count(arr,tsum,s1+arr[i],d,i-1,dp);
        return dp[i][s1]=(nottake+take);
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int tsum=0;
        for(auto i:arr) tsum+=i;
        vector<vector<int>>dp(n+1,vector<int>((tsum+d)/2+1,-1));
        return count(arr,tsum,0,d,n-1,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int tsum=0;
        int n=nums.size();
        for(auto i:nums) tsum+=i;
        vector<vector<int>>dp(n+1,vector<int>((tsum+1000)/2+1,-1));//max limit of target is 1000
        return count(nums,tsum,0,target,n-1,dp);
    }
};
// exactly same as "Count partitions with given difference" problem.
// check previous submission too
