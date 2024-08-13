class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        vector<int>ans(nums.size());
        for(int i=2*nums.size()-1;i>=0;i--){
            if(st.empty()){
                ans[i%nums.size()]=-1;
            }
            else if(!st.empty() && st.top()<=nums[i%nums.size()]){
                while(!st.empty() && st.top()<=nums[i%nums.size()]){
                    st.pop();
                }
                if(st.empty()){
                    ans[i%nums.size()]=-1;
                }
                else{
                    ans[i%nums.size()]=st.top();
                }
            }
            else if(!st.empty() && st.top()>nums[i%nums.size()]){
                ans[i%nums.size()]=st.top();
            }
            st.push(nums[i%nums.size()]);
        }
        return ans;
    }
};