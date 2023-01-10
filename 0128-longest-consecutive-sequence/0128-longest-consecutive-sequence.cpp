class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // O(Nlog N)
        
         int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int count=0;
        int maxi=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]+1==nums[i+1]){
                count++;
            }
            else if(nums[i]==nums[i+1]){  // ye bcoz agr aisa h 1 1 2 3 4 to vo rest na kre phle one ke bdd
                continue;
            }
            else{
                maxi=max(maxi,count);
                count=0;
            }
        }
        maxi=max(count,maxi);
        return maxi+1;
        
       // https://leetcode.com/problems/longest-consecutive-sequence/solution/
        
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
        
        return max(maxi,len)+1;
        
    }
    
    
};
