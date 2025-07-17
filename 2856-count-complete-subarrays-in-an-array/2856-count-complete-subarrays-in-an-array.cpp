class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        int k = mp.size();
        mp.clear();
        n=nums.size();
        
        int i=0,j=0,ans=0;
        while(j<n){
            mp[nums[j]]++;

            while(mp.size()==k){
                ans+=n-j;
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            j++;

        }

        return ans;
    }
};