//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int>dp(n,1),hash(n);
        int ans = -1;
        int lastIndex =-1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i] && dp[j]+1>dp[i]) {
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]> ans){
            ans = dp[i];
            lastIndex = i;
            }
        }
        vector<int>result;
        while(hash[lastIndex]!=lastIndex){
            result.push_back(arr[lastIndex]);
            lastIndex=hash[lastIndex];
        }
        result.push_back(arr[lastIndex]);
        reverse(result.begin(),result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends