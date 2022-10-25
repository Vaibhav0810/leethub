class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>mp1;
        
        for(auto s:strs){
            string t=s;
            sort(t.begin(),t.end());
            mp1[t].push_back(s);
        }
        vector<vector<string>>ans;
        
        for(auto it:mp1){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};