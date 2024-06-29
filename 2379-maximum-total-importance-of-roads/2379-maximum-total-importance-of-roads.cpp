class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>v(n,0);
        for(int i=0;i<roads.size();i++){
            v[roads[i][0]]++;
            v[roads[i][1]]++;
        }
        sort(v.begin(),v.end());
        long long ans=0;
        for(long long i=0;i<n;i++){
            ans+=(i+1)*v[i];
        }
        return ans;
    }
};