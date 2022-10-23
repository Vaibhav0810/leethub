class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        int sum2=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
            ans.push_back(nums[i]);
            }
            else{
                sum2=sum2+nums[i];
            }
        }

        int n=nums.size();
        sum2=sum2+nums[n-1];
        int sum1=(n*(2+n-1))/2;
        cout<<sum1;
    cout<<sum2;
        int store=sum1-sum2;
        ans.push_back(store);
        return ans;
        
        
    }
};