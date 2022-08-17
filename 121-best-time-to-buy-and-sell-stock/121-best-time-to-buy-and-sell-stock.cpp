class Solution {
public:
    
    
    //brute
    // int maxProfit(vector<int>& prices) {
    // int diff=0;
    // for(int i=0;i<prices.size();i++){
    //     for(int j=i+1;j<prices.size();j++){
    //         if(prices[j]-prices[i]>diff){
    //             diff=above line
    //         }
    //     }
    // }
    // return diff;
    // }
//    Optimised 
//        Time-O(N) Space-O(N)
    int maxProfit(vector<int>& prices) {
        int minPrice=1e5;
        int maxPrice=-1;
        int diff=0;
        
        for(int i=prices.size()-1;i>=0;i--){
            
            if(prices[i]<minPrice){
                minPrice=prices[i];
            }
             if(prices[i]>maxPrice){
                maxPrice=prices[i];
                minPrice=prices[i];
            }
             diff=max(diff,maxPrice-minPrice);
        }
        return diff;
    }
};