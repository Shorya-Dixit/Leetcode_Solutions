//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int>dpLIS(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]) dpLIS[i]=max(dpLIS[i],1+dpLIS[j]);
            }
        }
        vector<int>dpLDS(n,1);
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[j]<nums[i]) dpLDS[i]=max(dpLDS[i],1+dpLDS[j]);
            }
        }
        int ans=0;
        for(int i=1;i<n-1;i++){    // leave first and last index as the pivot cant be one of them
            if(dpLIS[i]>1 && dpLDS[i]>1) ans=max(ans,dpLDS[i]+dpLIS[i]-1);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
    }
}

// } Driver Code Ends