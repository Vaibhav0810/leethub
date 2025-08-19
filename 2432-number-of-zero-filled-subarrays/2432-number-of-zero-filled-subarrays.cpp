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
                int store=j-i;
                while(store>0){
                    ans+=store;
                    store--;
                }
                i=j;
            }
        }
        return ans;
    }
};