class Solution {
public:
//     bool isAnagram(string s, string t) {
//         unordered_map<char,int>mp1;
//         unordered_map<char,int>mp2;
        
//         for(auto it:s){
//             mp1[it]++;
//         }
//         for(auto it:t){
//             mp2[it]++;
//         }
        
//         if(mp1==mp2) return true;
//         return false;
        
//     }
    
    // with one map
    bool isAnagram(string s, string t){
    if(s.length()!=t.length()) return false;
    
    unordered_map<char,int>mp1;
    
    for(int i=0;i<s.length();i++){
        mp1[s[i]]++;
        mp1[t[i]]--;
    }
    for(auto it:mp1){
        if(it.second!=0) return false;
    }
    return true;
    }
//     Since the problem statement says that "the string contains only lowercase alphabets", we can simply use an array to simulate the unordered_map and speed up the code. The following implementation takes 12 ms.

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.length() != t.length()) return false;
//         int n = s.length();
//         int counts[26] = {0};
//         for (int i = 0; i < n; i++) { 
//             counts[s[i] - 'a']++;
//             counts[t[i] - 'a']--;
//         }
//         for (int i = 0; i < 26; i++)
//             if (counts[i]) return false;
//         return true;
//     }
// };
    
};