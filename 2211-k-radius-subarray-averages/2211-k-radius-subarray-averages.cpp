class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans;
        int i = 0, j = 0, n = nums.size();
        long long sum = 0;
        if (n < k * 2) {
            ans.resize(n, -1);
            return ans;
        }
        while (i < n && i <= (k * 2)) {
            sum += nums[i];
            i++;
        }
        i = 0;
        while (i<n && j<n) {
            if ((j - k) < 0 || (j + k) >= n) {
                // sum+=nums[j];
                ans.push_back(-1);
                j++;
            }
            else{
                ans.push_back(sum/(k*2+1));
                sum-=nums[i];
                i++;
                j++;
                if(j+k<n)
                sum+=nums[j+k];
            }
        }
        return ans;
    }
};