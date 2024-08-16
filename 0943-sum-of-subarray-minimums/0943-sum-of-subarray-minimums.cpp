class Solution {
public:
    int mod=1e9+7;
    vector<int>nsee(vector<int>& arr){    // next smaller and equal element
        vector<int>ans(arr.size());
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()) ans[i]=arr.size();
            else if(arr[i]<arr[st.top()]) {
                st.pop();
                i++;
                continue;
            }
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>pse(vector<int>& arr){    // previous smaller element
        vector<int>ans(arr.size());
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            if(st.empty()) ans[i]=-1;
            else if(arr[i]<=arr[st.top()]) {
                st.pop();
                i--;               
                continue;
            }
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>r=nsee(arr);
        vector<int>l=pse(arr);
        long long ans=0;
        for(int i=0;i<arr.size();i++){
            long left=i-l[i];
            long right=r[i]-i;
            ans+=(right*left)*arr[i]%mod;
            ans%=mod;
        }
        return int(ans);
    }
};