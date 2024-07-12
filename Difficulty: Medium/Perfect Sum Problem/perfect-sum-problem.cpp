//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9 + 7;
	int f(int arr[],int i,int target,vector<vector<int>>&dp){
	    if(i<0) {if(target==0) return 1;
	            else return 0;}
	    if(dp[i][target]!=-1) return dp[i][target];
	    int notTake=f(arr,i-1,target,dp);
	    int Take=0;
	    if(arr[i]<=target) Take=f(arr,i-1,target-arr[i],dp);
	    return dp[i][target]=(Take+notTake)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return f(arr,n-1,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends