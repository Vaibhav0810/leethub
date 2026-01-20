class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            int num = 0;
            while(num<=1000){
                if((num | num+1) == nums[i]){
                ans [i]=num;
                break;
                }
                // break;
                num++;
            }
        }
        return ans;
    }
};