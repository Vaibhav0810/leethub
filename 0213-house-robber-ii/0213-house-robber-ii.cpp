class Solution {
public:
    int rob(vector<int>& nums) {
       int maxi=0,prev=0;
       int n = nums.size();
       if(n==1) return nums[0];
       for(int i=0;i<n-1;i++){
            int curr = max(maxi,nums[i]+prev);
            prev=maxi;
            maxi=curr;
       } 
       int store = maxi;
       maxi =0,prev =0;
       for(int i=1;i<n;i++){
            int curr = max(maxi,nums[i]+prev);
            prev=maxi;
            maxi=curr;
       } 
       return max(maxi,store);

    }
};