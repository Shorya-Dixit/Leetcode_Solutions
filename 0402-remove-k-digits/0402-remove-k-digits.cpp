class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        int toRemove=k;
        stack<char>st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && (st.top()-'0')>(num[i]-'0') && toRemove>0){
                st.pop();
                toRemove--;
            }
            st.push(num[i]);
        }
        while(toRemove>0) {
            st.pop();
            toRemove--;
        }
        if(st.empty()) return "0";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        while(ans.size()!=1 && ans.size()!=0 && ans.back()=='0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};