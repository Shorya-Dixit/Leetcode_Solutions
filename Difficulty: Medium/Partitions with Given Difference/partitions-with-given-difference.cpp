//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod=1e9+7;
    int count(vector<int>& arr,int tsum, int s1,int d, int i,vector<vector<int>>&dp){
        if(i<0){
            if(2*s1==tsum+d) return 1;
            else return 0;
        }
        if(dp[i][s1]!=-1) return dp[i][s1];
        int nottake=count(arr,tsum,s1,d,i-1,dp);
        int take=0;
        if(2*(arr[i]+s1)<=tsum+d) take=count(arr,tsum,s1+arr[i],d,i-1,dp);
        return dp[i][s1]=(nottake+take)%mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int tsum=0;
        for(auto i:arr) tsum+=i;
        vector<vector<int>>dp(n+1,vector<int>((tsum+d)/2+1,-1));
        return count(arr,tsum,0,d,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends