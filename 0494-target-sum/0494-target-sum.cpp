class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        
        int s1=0,s2=0;
        
        int sum=0;
        int z=0;
        for(auto it:nums){
            if(it==0) z++;
            sum+=it;
        }
        int diff=target;
        
        if((sum<abs(target) )|| ((diff+sum)%2!=0)){
        return 0;
        }
        else s1=(diff+sum)/2;
        
        int n=nums.size();
        int dp[n+1][s1+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<s1+1;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        
        
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<s1+1;j++){
                   if (nums[i - 1] == 0)
                    dp[i][j] = dp[i - 1][j];
                else if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
             return pow(2, z) * dp[nums.size()][s1];
    }
};