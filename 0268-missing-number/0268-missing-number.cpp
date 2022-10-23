class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int>check;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size();i++){
            check.push_back(i);
        }
        bool shi=false;
        for(int i=0;i<nums.size();i++){
            if(check[i]!=nums[i]){
                shi=true;
                return check[i];
            }
        }
        if(shi==false){
            return check[check.size()-1];
        }
        return 0;
    }
};