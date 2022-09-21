class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int>ans;
        int sum=0;
        int j=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                sum=sum+nums[i];
            }
        }
        
        
        
        while(j<nums.size()){
            
            if(nums[queries[j][1]]%2==0){
            
                sum=sum-nums[queries[j][1]];
                
            }
            nums[queries[j][1]]=queries[j][0]+nums[queries[j][1]];
            
            if(nums[queries[j][1]]%2==0){
            
                sum=sum+nums[queries[j][1]];
                
            }
            
        
            ans.push_back(sum);
            
            j++;
        }
        return ans;
        
    }
};