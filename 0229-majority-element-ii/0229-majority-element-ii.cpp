class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=INT_MIN,ele2=INT_MIN;
        int store1=0,store2=0;
        
        for(int i=0;i<nums.size();i++){
            if(store1==0 && nums[i]!=ele2){
                ele1=nums[i];
                store1=1;
            }
            else if(store2==0 && nums[i]!=ele1){
                ele2=nums[i];
                store2=1;
            }
            else if(ele1==nums[i]) store1++;
            else if(ele2==nums[i]) store2++;
            else{
                store1--;
                store2--;
            }
        }
        vector<int>ans;
        store1=0,store2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1) store1++;
            if(nums[i]==ele2) store2++;
        }
        int mini = (nums.size()/3)+1;
        
        if(store1>=mini) ans.push_back(ele1);
        if(store2>=mini) ans.push_back(ele2);

        
        return ans;
    }
};