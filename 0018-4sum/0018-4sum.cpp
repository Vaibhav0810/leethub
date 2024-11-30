class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
vector<vector<int>> ans;
        set<vector<int>>st;
        
        if(nums.size()<4) return {};

for (int i = 0; i < nums.size() - 2; i++) {
    for (int j = i + 1; j < nums.size() - 1; j++) {
        unordered_set<long long> mp1;
        for (int k = j + 1; k < nums.size(); k++) {
            vector<int> check;
            long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
            if (mp1.find(fourth) == mp1.end()) {
                mp1.insert(nums[k]);
            } else {
                check.push_back(nums[i]);
                check.push_back(nums[j]);
                check.push_back(nums[k]);
                check.push_back((int)fourth);
                if(st.find(check)==st.end()){
                    ans.push_back(check);
                    st.insert(check);
                }
                else{
                    
                }
            }
        }
    }
}
return ans;
    }

};