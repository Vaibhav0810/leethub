class Solution {
public:
//     int pivotIndex(vector<int>& nums) {
        
//         // passed all but tle 
        
//         int sumL=0;
//         int sumR=0;
//         int sum=0;
//         for(int j=1;j<nums.size();j++){
//             sum=sum+nums[j];
//         }
//         if(sum==0) return 0;
        
        
        
//         for(int i=1;i<nums.size();i++){
//             sumL=sumL+nums[i-1];
//             for(int j=i+1;j<nums.size();j++){
//                 sumR=sumR+nums[j];
//             }
            
//             if(sumL==sumR) return i;
//             else sumR=0;
//         }
//         return -1;
//     }
    
    // optimised
    // phle pura sum le lia firr minus sb
    int pivotIndex(vector<int>& nums){
        int sum=0,leftsum=0;
        
        for(auto x:nums) sum+=x;
        
        for(int i=0;i<nums.size();i++){
            if(leftsum==sum-leftsum-nums[i]) return i;
                else leftsum+=nums[i];
        }
        return -1;
        
    }
    
};