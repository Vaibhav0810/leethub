class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        
        int toEat = n/2;
        map<int,int>mp1;
        for(auto it:candyType){
            mp1[it]++;
        }
        if(mp1.size()<toEat){
            return mp1.size();
        }
        return toEat;
    }
};