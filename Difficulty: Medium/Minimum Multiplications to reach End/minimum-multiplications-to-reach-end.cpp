//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mod=1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int>dist(100000,INT_MAX);
        queue<pair<int,int>>q;
        q.push({start,0});
        dist[start]=0;
        while(!q.empty()){
            int num=q.front().first;
            int step=q.front().second;
            q.pop();
            if(num==end) return step;
            for(auto it:arr){
                int newNum=(it*num)%mod;
                if(step+1<dist[newNum]){
                    dist[newNum]=step+1;
                    q.push({newNum,step+1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends