class Solution {
public:
    int f(vector<int>& nums, int target, int result, int ind){
        if(ind==nums.size()){
            if(result==target) return 1;
            else return 0;
        } 
        int add=f(nums,target,result+nums[ind],ind+1);
        int sub=f(nums,target,result-nums[ind],ind+1);
        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(nums,target,0,0);
    }
};