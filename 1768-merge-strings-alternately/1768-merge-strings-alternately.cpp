class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string ans="";
        
        int i=0,n=word1.size(),m=word2.size();
        
        while(i<n || i<m){
            if(i<n) ans.push_back(word1[i]);
            if(i<m) ans.push_back(word2[i]);
            i++;
        }
        return ans;
        
    }
};