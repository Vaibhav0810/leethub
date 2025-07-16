class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        set<long long>st;
        long long i=0,j=0,n=nums.size(),sum=0,ans=0;
        while(j<n){
            if(st.find(nums[j])==st.end()) st.insert(nums[j]),sum+=nums[j],j++;
            else st.erase(nums[i]),sum-=nums[i],i++;
            if(st.size()==k){
                ans=max(ans,sum);
                st.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
        }
        
        return ans;
        

    }
};