class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int,int>>st;
        int n = prices.size();
        vector<int>ans(n,0);

        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>=prices[i]){
                ans[st.top().second]=st.top().first-prices[i];
                st.pop();
            }
            st.push({prices[i],i});
        }

        while(!st.empty()){
            ans[st.top().second]=st.top().first;
            st.pop();
        }


        return ans;
    }
};