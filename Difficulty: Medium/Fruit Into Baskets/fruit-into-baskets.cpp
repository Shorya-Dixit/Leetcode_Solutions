//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        map<int,int>mp;
        int types=0;
        int left=0,right=0;
        int count=0;
        int maxfruit=0;
        for(int i=0;i<N;i++){
            mp[fruits[i]]++;
            if(mp[fruits[i]]==1) types++;
            if(types>2){
                while(types>2){
                    count--;
                    mp[fruits[left]]--;
                    if(mp[fruits[left]]==0) types--;
                    left++;
                }
            }
            count++;
            right++;
            maxfruit=max(maxfruit,count);
        }
        return maxfruit;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends