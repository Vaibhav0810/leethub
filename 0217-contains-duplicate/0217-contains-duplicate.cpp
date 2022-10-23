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
//     bool containsDuplicate(vector<int>& nums){
//     unordered_map<int,int>mp1;
//     for(auto it:nums){
//         mp1[it]++;
//     }
    
//     for(auto it:mp1){
//         if(it.second>1){
//             return true;
//         }
//     }
//     return false;
//         }
    
    // isme thda aur optimise ho skta h ki sara insert na krke jaise hi dikhe ki koi dup mil gya h return true
    
    bool containsDuplicate(vector<int>& nums){
        unordered_set<int>mp1;
        for(int i:nums){
            if(mp1.find(i)!=mp1.end()) return true;// mtlb kuch same mil gya h
            mp1.insert(i);// nhi to insert krdo
        }
        return false;
    }
    
};