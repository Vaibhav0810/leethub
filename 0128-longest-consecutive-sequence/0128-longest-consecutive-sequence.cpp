class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
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