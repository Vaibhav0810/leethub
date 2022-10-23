class Solution {
public:
    
    // brute
    // bool containsDuplicate(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());
    //     for(int i=0;i<nums.size()-1;i++){
    //         if(nums[i]==nums[i+1]) return true;
    //     }
    //     return false;
    // }
    
    // optimised
    // O(N) and O(N)
    bool containsDuplicate(vector<int>& nums){
    unordered_map<int,int>mp1;
    for(auto it:nums){
        mp1[it]++;
    }
    
    for(auto it:mp1){
        if(it.second>1){
            return true;
        }
    }
    return false;
        }
};