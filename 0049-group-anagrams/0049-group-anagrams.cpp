class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // isme ik map bna dia string and vector type ka ab hm string ko sort krenge aur uske bdd jin jin ka sort same hoga unko ik mei push kr denge 
        // baaki ko alg mei aise pura sorted aajayega aur usse firr array mei push kr denge 
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