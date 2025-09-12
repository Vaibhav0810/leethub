class Solution {
public:

    bool checkVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }

    bool doesAliceWin(string s) {
        int vowels=0;
        for(auto it:s){
            if(checkVowel(it)){
                vowels++;
            }
        }

        if(vowels==0) return false;
        if(vowels%2!=0) return true;

        // int count=0;
        return true;
        

    }
};