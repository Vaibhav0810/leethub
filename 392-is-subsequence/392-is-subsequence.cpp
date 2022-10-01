class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        bool check=false;
        int store=0;
        for(int i=0;i<s.length();i++){
            check=false;
            for(int j=store;j<t.length();j++){
                if(s[i]==t[j]){
                    check=true;
                    store=j+1;
                    break;
                }
                
            }
            if(check==false) return false;
            
            
        }
        return true;
    }
};