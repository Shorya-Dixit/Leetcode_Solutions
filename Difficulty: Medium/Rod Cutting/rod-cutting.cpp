//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int knapsackUtil(int val[], int ind, int n, vector<vector<int>>& dp) {
    // Base case: if we're at the first item
    if (ind <0) {
        // Calculate and return the maximum value for the given weight limit
        return 0;
    }
    // If the result for this index and weight limit is already calculated, return it
    if (dp[ind][n] != -1)
        return dp[ind][n];
        
    // Calculate the maximum value without taking the current item
    int notTaken = 0 + knapsackUtil(val, ind - 1, n, dp);
    // Calculate the maximum value by taking the current item
    int taken = INT_MIN;
    int rodLength=ind+1;
    if (rodLength <= n)
        taken = val[ind] + knapsackUtil(val, ind, n - rodLength, dp);
        
    // Store the maximum value in the DP table and return it
    return dp[ind][n] = max(notTaken, taken);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return knapsackUtil(price, n - 1, n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends