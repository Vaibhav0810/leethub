class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        for(int i=0;i<nums.size();i++){
            int st = nums[i];
            int st2=st;
            while(i+1<nums.size() && nums[i+1]==st2+1){
                st2++;
                i++;
            }
            if(st==st2) ans.push_back(to_string(st));
            else {
                ans.push_back(to_string(st)+"->"+to_string(st2));
            }
        }
        return ans;
    }
};