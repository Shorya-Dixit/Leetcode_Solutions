class StockSpanner {
public:
// used previous greater element method
    stack<pair<int,int>>st;
    int ind=-1;
    StockSpanner() {
        ind=-1;
    } 
    int next(int price) {
        ind++;
        while(!st.empty() && st.top().second<=price) st.pop();
        int ans=ind+1;
        if(!st.empty()) ans=ind-st.top().first;
        st.push({ind,price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */