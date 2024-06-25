//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<int> prev(4, -1);
        for(int last=0;last<4;last++)
        {
            for(int j=0;j<3;j++)
            {
                if(j!=last) prev[last]=max(prev[last],points[0][j]);
            }
        }
        for(int i=1;i<n;i++)
        {
            vector<int> temp(4, -1);
            for(int last=0;last<4;last++)
            {
                for(int j=0;j<3;j++)
                {
                    if(j!=last) temp[last]=max(temp[last],points[i][j]+prev[j]);
                }
            }
            prev=temp;
        }
        return prev[3];
    }
};
// space optimization on tabulation approach
// j is representing task here
// i is refering to day here and last means what task was performed on the previous day.
// i.e. when day is n-1 (last day) the task performed before it was nothing i.e. 3.
// we are going from last to first, therefore saying last day for the day after the current day.


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends