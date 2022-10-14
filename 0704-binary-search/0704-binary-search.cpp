class Solution {
public:
    // recursive
    int search(vector<int>& nums, int target) {
        
        return help(0,nums.size()-1,nums,target);
        
    }
    
    int help(int start,int end,vector<int>nums,int target){
        int mid=(start+end)/2;
        if(start>end) return -1;
        if(target>nums[mid]){
            return help(mid+1,end,nums,target);
        }
        else if(target<nums[mid]){
            return help(start,mid-1,nums,target);
        }
        else if(target==nums[mid]){
            return mid;
        }
        return -1;
    }
    //iterative 
    // int search(vector<int>& nums, int target) {
    //     int start=0,end=nums.size()-1,mid;
    //     while(start<=end){
    //         mid=(start+end)/2;
    //         if(nums[mid]==target) return mid;
    //         else if(nums[mid]<target){
    //             start=mid+1;
    //         }
    //         else{
    //             end=mid-1;
    //         }
    //     }
    //     return -1;
    // }
};