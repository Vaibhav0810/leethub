class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = -1;
        int store = 0;
        
        for(int i=0;i<nums.size();i++){
            if(store==0){
                ele=nums[i];
                store++;
                continue;
            }
            if(nums[i]==ele){
                store++;
            }
            else store--;
        }
        return ele;
    }
};