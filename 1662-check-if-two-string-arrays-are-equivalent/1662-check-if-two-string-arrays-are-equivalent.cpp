class Solution {
public:
//     bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
//         string w1="";
//         string w2="";
        
//         for(int i=0;i<word1.size();i++){
//             w1=w1+word1[i];
//         }
//         for(int i=0;i<word2.size();i++){
//             w2=w2+word2[i];
//         }
//         if(w1==w2) return true;
//         return false;
//     }
    
    // Optimised
    // O(1) space
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2){
        int i=0,j=0;
        int m=0,n=0;
        
        while(i<word1.size() && j<word2.size()){
            if(word1[i][m++]!=word2[j][n++]){
                return false;
            }
            if(m>=word1[i].size()){
                i++,m=0;
            }
            if(n>=word2[j].size()){
                j++,n=0;
            }
            
        }
        return i==word1.size() && j==word2.size();
    }
    
};