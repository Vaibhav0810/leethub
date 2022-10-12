class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // brute O(nlog n)
//         if(nums.size()==1) return nums[0];
        
//         sort(nums.begin(),nums.end());
        
//         for(int i=0;i<nums.size();i=i+2){
//             if(nums[i]!=nums[i+1]){
//                 return nums[i];
//             }
//         }
//         return 0;
        
        //Optimised
        
        //O(N) and O(N)
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(auto it:mp){
            if(it.second==1){
                return it.first;
            }
        }
        return 0;
    }
        
    
};