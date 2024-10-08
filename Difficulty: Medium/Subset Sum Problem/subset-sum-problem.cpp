//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<bool>> dp(arr.size()+1, vector<bool>(sum + 1, 0));
        dp[0][arr[0]]=true;
        for(int i=0;i<arr.size();i++) dp[i][0]=true;
        for(int i=1;i<arr.size();i++)
        {
            for(int sumi=1;sumi<=sum;sumi++)
            {
                bool taken=false;
                if(arr[i]<=sumi) taken=dp[i-1][sumi-arr[i]];
                bool nottaken=dp[i-1][sumi];
                dp[i][sumi]=taken|nottaken;
            }
        }
        return dp[arr.size()-1][sum];
    }
    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends