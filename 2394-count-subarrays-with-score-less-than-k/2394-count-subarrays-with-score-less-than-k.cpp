class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        long long sum=0;
        long long mul=1;
        int n=nums.size(),j=0,i=0;

        while(j<n){
            sum+=nums[j];
            mul=sum*(j-i+1);
            while(i<=j && mul>=k){
                sum-=nums[i];
                i++;
                mul=sum*(j-i+1);
            }
            ans=ans+j-i+1;
            // cout<<ans<<" "<<j<<endl;
            j++;
        }
        return ans;
    }
};