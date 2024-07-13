//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapsackUtil(int wt[], int val[], int ind, int W, vector<vector<int>>& dp) {
        // Base case: if we're at the first item
        if (ind < 0) {
            // Calculate and return the maximum value for the given weight limit
            return 0;
        }
        
        // If the result for this index and weight limit is already calculated, return it
        if (dp[ind][W] != -1)
            return dp[ind][W];
            
        // Calculate the maximum value without taking the current item
        int notTaken = 0 + knapsackUtil(wt, val, ind - 1, W, dp);
        
        // Calculate the maximum value by taking the current item
        int taken = INT_MIN;
        if (wt[ind] <= W)
            taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp);
            
        // Store the maximum value in the DP table and return it
        return dp[ind][W] = max(notTaken, taken);
    }
    
    int knapSack(int N, int W, int val[], int wt[]) {
        
        vector<vector<int>> dp(N, vector<int>(W + 1, -1)); 
        return knapsackUtil(wt, val, N - 1, W, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends