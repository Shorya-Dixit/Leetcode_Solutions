//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int lowerBound(vector<int>v,int num){
        int low=0;
        int high=v.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(v[mid]>num) high=mid-1;
            else if(v[mid]<num) low=mid+1;
            else return mid;
        }
        return low;
    }
    int longestSubsequence(int n, int a[])
    {
        vector<int>ans;
        int last=0;
        ans.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]<ans[last]){
                ans[lowerBound(ans,a[i])]=a[i];
            }
            else if(a[i]>ans[last]){
                ans.push_back(a[i]);
                last++;
            }
        }
        return ans.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends