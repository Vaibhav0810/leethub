class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // first find prefix sum 
        
        vector<int>pre;
        int maxi=INT_MIN;
        int indexMaxi=-1;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                pre.push_back(nums[i]);
            }
            else{
                if(pre[i-1]<0){
                    pre.push_back(nums[i]);
                }
                else
                    pre.push_back(nums[i]+pre[i-1]);
            }
            if(pre[i]>maxi){
                maxi=pre[i];
                
            }
        }
        
        return maxi;
                
        
    }
};