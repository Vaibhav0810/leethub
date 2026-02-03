class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool inc = false;
        bool dec= false;
        bool inc2=false;
        int n= nums.size();
        int i=1;
        
            while(i<n && nums[i-1]<nums[i]){
                i++;
                inc=true;
            }
            while(i<n && inc==true && nums[i-1]>nums[i]){
                i++;
                dec = true;
            }
            while(i<n && inc == true && dec && nums[i-1]<nums[i]){
                i++;
                inc2=true;
            }
        
        if(i==n && inc && inc2 && dec) return true;
        return false;
    }
};