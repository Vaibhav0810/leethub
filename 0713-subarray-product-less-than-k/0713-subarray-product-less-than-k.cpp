class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;
        int i = 0, j = 0, n = nums.size();
        long long prod = 1;
        int count = 0;

        while (i < n && j < n) {
            prod *= nums[j];

            while (prod >= k && i <= j) {
                prod /= nums[i];
                i++;
            }

            count = count + j - i + 1;
            j++;
        }
        return count;
    }
};