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
//         unordered_map<int,int>mp;
//         for(int i=0;i<nums.size();i++){
//             mp[nums[i]]++;
//         }
        
//         for(auto it:mp){
//             if(it.second==1){
//                 return it.first;
//             }
//         }
//         return 0;
//     }
        
        
        // More optimise
        // refer notes
        // we are taking xor here 
        // xor of same number is 0 and opposite is 1 and xor of any number with 0 is that number 
        // so jb hm xor lenge 5 ^ 1 ka to 4 aayega binary se krenge 
        // eg 1
        // 2 ^ 2 =0 0^1 =1
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size();i++){
            nums[i+1]=nums[i]^nums[i+1];
        }
        return nums[nums.size()-1];
    }
};