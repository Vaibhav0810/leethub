class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp1;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (mp1.find(target - nums[i]) == mp1.end()) {
            mp1[nums[i]] = i;
        } else {
            int store = mp1[target - nums[i]];
            return {i, store};
        }
    }
    return {};
    }
};