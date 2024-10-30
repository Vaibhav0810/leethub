class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> posi;
        vector<int> negi;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) posi.push_back(nums[i]);
            else negi.push_back(nums[i]);
        }
        int j = 0;
        for(int i=0;i<posi.size();i++){
            nums[j]=posi[i];
            j++;
            nums[j]=negi[i];
            j++;
        }
        return nums;
        
    }
};