class Solution {
public:
    vector<int> rightHeight(vector<int>& nums) {
        vector<int>ans(nums.size());
        int height=0;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]=height;
            height=max(height,nums[i]);
        }
        return ans;
    }
    vector<int> leftHeight(vector<int>& nums) {
        vector<int>ans(nums.size());
        int height=0;
        for(int i=0;i<nums.size();i++){
            ans[i]=height;
            height=max(height,nums[i]);
        }
        return ans;
    }
    int trap(vector<int>& height) {
        vector<int>left=leftHeight(height);
        vector<int>right=rightHeight(height);
        int area=0;
        for(int i=0;i<height.size();i++){
            if(left[i]>height[i] && right[i]>height[i]) area+=min(right[i]-height[i],left[i]-height[i]);
        }
        return area;
    }
};