class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        // nhi chl rha h kuch bhi
        
        // brute tle time - O(N^3)
        // Space - O(1)
        // for(int i=0;i<nums.size()-2;i++){
        //     for(int j=i+1;j<nums.size()-1;j++){
        //         for(int k=j+1;k<nums.size();k++){
        //             if(nums[i]<nums[j] && nums[j]<nums[k]){
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // return false;
        
        //Optimised
        
        //The question only asks whether it exists. The key to prove this solution is always correct is that there is always a number before c2 that is less than c2, which might or might not be c1 (otherwise, c2==INT_MAX and wont get updated). Now if a number is greater than c2, we can safely return true
        
        // phle hm c1 mei minimum element daalenge aur agr uske bdd hme uss se koi bda element mil ta h to c2 ab agr koi teesra element mil rha h jo inn dono se bda h to mtlb hmari condition shi ho gyi to true return kr denge
        int c1=INT_MAX,c2=INT_MAX;
        
        for(int x:nums){
            if(x<=c1){
                c1=x;
            }
            else if(x<=c2){
                c2=x;
            }
            else return true;
        }
        return false;
        
    }
};