class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0,n=prices.size()-1;
        int buy,sell;
        int i = 0;
        while(i<n){
            while(i<n && prices[i+1]<=prices[i]) i++;
            buy =  prices[i];
            while(i<n && prices[i+1]>prices[i])i++;
            sell = prices[i];

            ans+=sell-buy;
        }
        return ans;
    }
};