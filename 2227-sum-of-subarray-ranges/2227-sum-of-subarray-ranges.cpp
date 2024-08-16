class Solution {
public:
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
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int>r=nsee(arr);
        vector<int>l=pse(arr);
        long ans=0;
        for(int i=0;i<arr.size();i++){
            long left=i-l[i];
            long right=r[i]-i;
            ans+=(right*left)*arr[i];
        }
        return ans;
    }
    vector<int>nbee(vector<int>& arr){    // next bigger and equal element
        vector<int>ans(arr.size());
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()) ans[i]=arr.size();
            else if(arr[i]>arr[st.top()]) {
                st.pop();
                i++;
                continue;
            }
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>pbe(vector<int>& arr){    // previous bigger element
        vector<int>ans(arr.size());
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            if(st.empty()) ans[i]=-1;
            else if(arr[i]>=arr[st.top()]) {
                st.pop();
                i--;               
                continue;
            }
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int>r=nbee(arr);
        vector<int>l=pbe(arr);
        long ans=0;
        for(int i=0;i<arr.size();i++){
            long left=i-l[i];
            long right=r[i]-i;
            ans+=(right*left)*arr[i];
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        ans= sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
        return ans;
    }
};