class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<=1) return true;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]==0){
                int j=0;
                while(j-nums[i]>=0 && i>=0){
                    if(i==0) return false;
                    j++;
                    i--;
                }
            }
        }
        return true;
    }
};