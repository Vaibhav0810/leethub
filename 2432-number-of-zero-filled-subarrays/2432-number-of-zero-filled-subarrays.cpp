class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int j=0,n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                while(j<n && nums[j]==0){
                    j++;
                }
                long long store=j-i;
                ans+=(long long)store*(store+1)/2;
                i=j;
            }
        }
        return ans;
    }
};