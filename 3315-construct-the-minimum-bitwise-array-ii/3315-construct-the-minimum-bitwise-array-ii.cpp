class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            bool found=false;
            if(nums[i]==2){
                 ans.push_back(-1);
                 continue;
            }
            for(int j=0;j<32;j++){
                if((nums[i] & (1<<j))>0) continue;
                int prev = j-1;
                int x = (nums[i]^(1<<(j-1)));
                ans.push_back(x);
                found=true;
                 break;

            }
            if(!found) ans.push_back(-1);
        }
        return ans;
    }
};