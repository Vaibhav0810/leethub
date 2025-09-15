class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arr, int w, int m) {
        unordered_map<int, int> mp;
        vector<bool>discarded(arr.size(),false);
        int n = arr.size();
        int ans = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            mp[arr[j]]++;
            if (mp[arr[j]] > m) {
                ans++;
                mp[arr[j]]--;
                discarded[j]=true;
            }

            if (j - i + 1 == w) {
                if (mp.count(arr[i]) && discarded[i]==false) {
                    mp[arr[i]]--;
                    if (mp[arr[i]] == 0)
                        mp.erase(arr[i]);
                    
                }
                i++;
            }
        }
        return ans;
    }
};