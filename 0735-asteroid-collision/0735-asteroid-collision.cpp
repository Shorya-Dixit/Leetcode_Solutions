class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            if(st.empty() || st.top()*asteroids[i]>0 || (st.top()<0 && asteroids[i]>0)) st.push(asteroids[i]);
            else if (st.top()>0 && asteroids[i]<0){
                if(abs(st.top())<abs(asteroids[i])){
                    st.pop(); // st.top() destroy ho jaega
                    i--;  // matlab asteroids[i] direct destroy ni krenge, firse check krenge
                }
                else if(abs(st.top())==abs(asteroids[i])){
                    st.pop();   // st.top() destroy ho jaega
                    continue;   // continue matlab ki asteroids[i] destroy ho jaega
                } // is case me dono destroy ho gae
                else continue;   // continue matlab ki sirf asteroids[i] destroy ho jaega
            }
        }
        vector<int>ans(st.size());
        for(int i=st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};