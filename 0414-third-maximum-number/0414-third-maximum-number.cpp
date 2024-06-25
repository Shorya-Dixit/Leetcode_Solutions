class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1=LLONG_MIN,max2=LLONG_MIN,max3=LLONG_MIN;
        for(int i=0;i<nums.size();i++){
            if(max1<nums[i]){
                max3=max2;
                max2=max1;
                max1=nums[i];
            }
            else if(max1>nums[i] && max2<nums[i]){
                max3=max2;
                max2=nums[i];
            }
            else if(max2>nums[i] && max3<nums[i]){
                max3=nums[i];
            }
        }
        if(max3<INT_MIN) return max1;
        return max3;
    }
};