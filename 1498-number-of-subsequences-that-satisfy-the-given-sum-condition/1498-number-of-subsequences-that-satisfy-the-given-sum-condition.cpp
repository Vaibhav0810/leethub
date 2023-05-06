class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        
        vector<int>arr(nums.size(),0);
        sort(nums.begin(),nums.end());
        
        arr[0]=1;
        int mod=1e9+7;
        
        for(int i=1;i<nums.size();i++){
            arr[i]=(arr[i-1]*2)%mod;
        }
        int n=nums.size();
        int left=0,right=n-1;
        int ans=0;
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                ans+=arr[right-left];
                ans=ans%mod;
                left++;
            }
            else right--;
        }
        return ans%mod;
    }
};