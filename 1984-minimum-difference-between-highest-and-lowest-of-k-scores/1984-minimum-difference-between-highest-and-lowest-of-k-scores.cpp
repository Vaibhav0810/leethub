class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        if(k==n) return nums[n-1]-nums[0];
        int i = 0,j=k-1;
        int ans = INT_MAX;
        while(j<n){
            ans=min(ans,nums[j]-nums[i]);
            i++;
            j++;
        }
        return ans;
    }
};