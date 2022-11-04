class Solution {
public:
    
    bool checkV(char s){
        if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u' || s =='A' || s=='E' || s=='I' || s=='O' || s=='U'){
            return true;
        }
        else return false;
    }
    
    string reverseVowels(string s) {
        int i=0,j=s.length()-1;
        
        while(i<j){
            if(checkV(s[i])==0){
                i++;
            }
            if(checkV(s[j])==0){
                j--;
            }
            if(checkV(s[i])==1 && checkV(s[j])==1){
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};