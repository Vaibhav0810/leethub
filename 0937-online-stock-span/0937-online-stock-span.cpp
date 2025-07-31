class StockSpanner {
public:
    // same as daily temp Q
    // isme hm dekhenge agr stack mei hmse koi chota ni h to push krdo
    // agr koi h to 1 pair mei count store krte chlo ki kitne log aur chote h

stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res=1;
        while(!st.empty() && st.top().first<=price){
            res+=st.top().second;
            st.pop();
        }
        st.push({price,res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */