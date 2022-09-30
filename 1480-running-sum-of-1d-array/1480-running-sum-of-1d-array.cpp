class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        vector<int>ans;
        int sum=nums[0];
        ans.push_back(sum);
        for(int i=1;i<nums.size();i++){
            sum=sum+nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};