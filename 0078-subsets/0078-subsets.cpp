class Solution {
public:
    void get(vector<int>& nums, int i, vector<int>v, vector<vector<int>>&ans){
        if(i==nums.size()) {
            ans.push_back(v);
            return;
        }
        get(nums,i+1,v,ans);
        v.push_back(nums[i]);
        get(nums,i+1,v,ans);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        get(nums,0,v,ans);
        return ans;
    }
};