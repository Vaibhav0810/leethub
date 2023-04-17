class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans(candies.size(),0);
        int maxi=INT_MIN;
        for(auto it:candies){
            maxi=max(it,maxi);
        }
        
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=maxi) ans[i]=true;
            else ans[i]=false;
        }
        
        return ans;
        
    }
};