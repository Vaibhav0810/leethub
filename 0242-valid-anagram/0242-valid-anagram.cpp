class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        
        for(auto it:s){
            mp1[it]++;
        }
        for(auto it:t){
            mp2[it]++;
        }
        
        if(mp1==mp2) return true;
        return false;
        
    }
};