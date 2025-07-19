class Solution {
public:
    string minWindow(string nums, string t) {
        int i = 0, j = 0, m = nums.length(), n = t.length(), ans = INT_MAX,
            len = 0, start = 0, end = 0;

        map<int, int> mp1;
        for (auto it : t) {
            mp1[it]++;
        }

        while (j < m) {

            if (mp1.find(nums[j]) != mp1.end()) {
                if(mp1[nums[j]]>0) n--;
                mp1[nums[j]]--;
                
            }
            while (i <= j && n == 0) {
                int cw=j-i+1;
                if(ans>cw){
                    start=i;
                    ans=cw;
                }
                if (mp1.find(nums[i]) != mp1.end()) {
                    mp1[nums[i]]++;
                    if(mp1[nums[i]]>0) n++;
                }
                i++;
            }

            j++;
        }

        return ans==INT_MAX ? "" : nums.substr(start,ans);
    }
};