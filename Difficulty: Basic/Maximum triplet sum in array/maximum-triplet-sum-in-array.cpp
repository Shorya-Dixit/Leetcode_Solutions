//{ Driver Code Starts
#include <iostream>
#include <limits.h>
#include <sstream>
#include <vector>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxTripletSum(vector<int> &arr) {
        
        vector<int>pge(arr.size());
        int prevGreatest=INT_MIN;
        for(int i=0;i<arr.size();i++){
            pge[i]=prevGreatest;
            if(arr[i]>prevGreatest) prevGreatest=arr[i];
        }
        
        vector<int>nge(arr.size());
        int nextGreatest=INT_MIN;
        for(int i=arr.size()-1;i>=0;i--){
            nge[i]=nextGreatest;
            if(arr[i]>nextGreatest) nextGreatest=arr[i];
        }
        
        int ans=INT_MIN;
        for(int i=1;i<arr.size()-1;i++){
            int maxTripletSum=pge[i]+nge[i]+arr[i];
            ans=max(maxTripletSum,ans);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob; // Move the class instantiation here
        cout << ob.maxTripletSum(nums) << "\n";
    }
    return 0;
}

// } Driver Code Ends