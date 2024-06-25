//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

  class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        map<int,int> mpp;
        int n=nums.size();
        for(auto x:nums){
            mpp[x]++;
        }
        
        vector<pair<int,int>> v(n);
        
        int l=0;
        
        
        // interchanging the key and value such that it would be easier to sort the function.
        for(auto x:mpp){
            v[l].second=x.first;
            v[l].first=x.second;
            l++;
        }
        
        sort(v.begin(),v.end());
        
        vector<int>ans(k);
        for(int i=0;i<k;i++){
            ans[i]=v[n-i-1].second;
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends