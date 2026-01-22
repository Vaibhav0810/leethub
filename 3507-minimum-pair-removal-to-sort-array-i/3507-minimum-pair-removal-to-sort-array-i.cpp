class Solution {
public:
    bool check(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int sum = INT_MAX;
        int ans = 0;
        if (check(nums))
            return 0;
        int store = 0;

        while (!check(nums) && nums.size() > 0) {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i - 1] + nums[i] < sum) {
                    sum = nums[i - 1] + nums[i];
                    store = i;
                }
            }
            nums.erase(nums.begin() + store - 1);
            nums[store - 1] = sum;
            ans++;
            for(auto it:nums) cout<<it<<" ";
            cout<<endl;
            sum=INT_MAX;
        }

        return ans;
    }
};