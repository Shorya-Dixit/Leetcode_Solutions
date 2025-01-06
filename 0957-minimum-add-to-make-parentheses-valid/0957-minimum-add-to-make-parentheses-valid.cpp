class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(auto it:s){
            if(it=='(') st.push(it);
            else {
                if(!st.empty() && st.top()=='(') st.pop();
                else st.push(')');
            }
        }
        return st.size();
    }
};