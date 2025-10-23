class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // O(N) space

        // vector<int>dp(n,0);
        // dp[0]=nums[0];
        // if(n>1)
        //     dp[1]=max(nums[0],nums[1]);

        // for(int i=2;i<n;i++){
        //     dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        // }
        // return dp[n-1];

        // O(1) Space

        int prv = 0;
        int maxi =0;

        for(int i=0;i<n;i++){
            int curr = max(maxi,prv+nums[i]);
            prv = maxi;
            maxi = curr;
        }

        return maxi;
    

    }
};