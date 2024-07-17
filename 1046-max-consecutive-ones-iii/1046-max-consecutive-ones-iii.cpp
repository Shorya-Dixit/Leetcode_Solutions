class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int flipped=0;
        int maxOne=0;
        int countOne=0;
        int left=0,right=0;
        while(left<= right && right<nums.size()){
            if(nums[right]==1) countOne++;
            else {
                if(flipped<k){
                    countOne++;
                    flipped++;
                }
                else{
                    while(flipped>=k){
                        if(nums[left]==0) flipped--;
                        left++;
                        countOne--;
                    }
                    flipped++;
                    countOne++;
                }
            }
            right++;
            maxOne=max(maxOne,countOne);
        }
        return maxOne;
    }
};