class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = -1;

        for(int i=0;i<nums.size();i++){
            if(maxReachable!=-1 && i>maxReachable) return false;
            maxReachable= max(maxReachable,nums[i]+i);

        }

        if(maxReachable>=nums.size()-1) return true;
        return false;

    }
};