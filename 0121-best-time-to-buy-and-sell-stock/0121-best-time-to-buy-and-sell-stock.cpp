class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b=prices.size()-2,s=prices.size()-1;
        
        // int n =price.size()-1;
        int maxi =0;
        while(b>=0){
            int diff = prices[s]-prices[b];
            // cout<<prices[b]<<" "<<prices[s]<<endl;
            maxi=max(maxi,diff);
            // cout<<maxi<<endl;
            
            if(prices[b]>prices[s]){
                s=b;
                b--;
            }
            else{
                b--;
            }
            
        }
        return maxi;
        
    }
};