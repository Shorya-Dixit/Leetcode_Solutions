class Solution {
public:
    vector<int> rightBoundary(vector<int>& nums) {
        stack<int>st;
        vector<int>ans(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            if(st.empty()){
                ans[i]=nums.size();
            }
            else if(!st.empty() && nums[st.top()]>=nums[i]){
                while(!st.empty() && nums[st.top()]>=nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans[i]=nums.size();
                }
                else{
                    ans[i]=st.top();
                }
            }
            else if(!st.empty() && nums[st.top()]<nums[i]){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> leftBoundary(vector<int>& nums) {
        stack<int>st;
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(st.empty()){
                ans[i]=0;
            }
            else if(!st.empty() && nums[st.top()]>=nums[i]){
                while(!st.empty() && nums[st.top()]>=nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans[i]=0;
                }
                else{
                    ans[i]=st.top()+1;
                }
            }
            else if(!st.empty() && nums[st.top()]<nums[i]){
                ans[i]=st.top()+1;
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left=leftBoundary(heights);
        vector<int>right=rightBoundary(heights);
        int area=0;
        for(int i=0;i<heights.size();i++){
            area=max(area,(right[i]-left[i])*heights[i]);
        }
        return area;
    }
};