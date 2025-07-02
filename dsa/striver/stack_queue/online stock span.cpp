class StockSpanner {
public:
    // day , value.
    stack<pair<int, int>> st;
    int curr ;
    StockSpanner() {
        curr =1;
        st.push({curr, INT_MAX});
        curr++;
    }
    
    int next(int price) {
        while(!st.empty() && st.top().second <= price){
            st.pop();
        }
        int last =  st.top().first;
        st.push({curr++, price});
        return curr -1 - last;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
