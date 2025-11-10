class Solution {
public:
    int minOperations(vector<int>& nums) {

        // brute force O(N^2)

        // map<int, int> mp1;
        // for (auto it : nums) {
        //     mp1[it]++;
        // }
        // int ans;
        // if (mp1.find(0) != mp1.end()) {
        //     ans = 0;
        // } else {
        //     ans = 1;
        // }

        // bool first = false;

        // if (nums.size() == 1)
        //     return ans;

        // int n = nums.size();

        // for (auto it : mp1) {
        //     if (!first) {
        //         first = true;
        //         continue;
        //     }
        //     for (int i = 0; i < nums.size(); i++) {
        //         if (nums[i] == it.first) {
        //             while (i < n &&
        //                    (nums[i] == it.first || nums[i] > it.first)) {
        //                 i++;
        //             }
        //             ans++;
        //         }
        //     }
        // }

        // return ans;

        // optimal using monotonic stack

        stack<int> s;
        int ans = 0;

        for (int a : nums) {
            while (!s.empty() && s.top() > a) {
                s.pop();
            }

            if (a == 0)
                continue;
            if (s.empty() || s.top() < a) {
                s.push(a);
                ans++;
            }
        }

        return ans;
    }
};