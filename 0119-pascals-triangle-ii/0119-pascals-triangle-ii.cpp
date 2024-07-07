class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        ans.push_back(1);
        long long x=1;
        for(int i=1;i<=rowIndex;i++){
            x*=(rowIndex-i+1);
            x/=i;
            ans.push_back(x);
        }
        return ans;
    }
};