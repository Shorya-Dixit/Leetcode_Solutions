class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int right=-1;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<=right){
                right=max(right,intervals[i][1]);
                ans.back()[1]=right;
            }
            else if(intervals[i][0]>right){
                right=max(right,intervals[i][1]);
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};