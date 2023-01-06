class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // brute force O(n log n)
        
//         if(nums.size()==0) return 0;
        
//         sort(nums.begin(),nums.end());
//         int count=0;
//         int maxi=0;
//         for(int i=0;i<nums.size()-1;i++){
//             if(nums[i]+1==nums[i+1]){
//                 count++;
//             }
//             else if(nums[i]==nums[i+1]){
//                 continue;
//             }
//             else{
//                 maxi=max(maxi,count);
//                 count=0;
//             }
//         }
//         maxi=max(count,maxi);
//         return maxi+1;
        
        // O(N)
        
        set<int>st(nums.begin(),nums.end());
        if(nums.size()==0) return 0;
        int len=0;
        int maxi=0;
        for(auto it:st){
            if(st.find(it-1)!=st.end()){
                maxi++;
            }
            else{
                
                len=max(maxi,len);
            maxi=0;}
        }
        
        return max(maxi,len)+1;;
    }
};