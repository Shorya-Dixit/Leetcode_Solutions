class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a1, vector<int>& a2) {
        stack<int>st;
        unordered_map<int,int>mp;
        for(int i=a2.size()-1;i>=0;i--){
            if(st.empty()){
                mp[a2[i]]=-1;
            }
            else if(!st.empty() && st.top()<=a2[i]){
                while(!st.empty() && st.top()<=a2[i]){
                    st.pop();
                }
                if(st.empty()){
                    mp[a2[i]]=-1;
                }
                else{
                    mp[a2[i]]=st.top();
                }
            }
            else if(!st.empty() && st.top()>a2[i]){
                mp[a2[i]]=st.top();
            }
            st.push(a2[i]);
        }
        vector<int>ans(a1.size());
        for(int i=0;i<a1.size();i++){
             ans[i]=mp[a1[i]];
        }
        return ans;
    }
    
};