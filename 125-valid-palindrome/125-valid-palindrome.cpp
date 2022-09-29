class Solution {
public:
    bool isPalindrome(string s) {
        
        //stack<char>st;
        
//         string st2;
        
//         for(int i=0;i<s.length();i++){
//             if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9') ){
//                 //st.push(s[i]);
//                 st2.push_back(s[i]);
//             }
//             else if(s[i]>='A' && s[i]<='Z'){
//                 //st.push(tolower(s[i]));
//                 st2.push_back(tolower(s[i]));
//             }
//         }
//         int i=0;
//         int j=st2.length()-1;
        
//         while(i<=j){
//             if(st2[i]!=st2[j]){
//                 return false;
//             }
//             else{
//                 i++;
//                 j--;
//             }
//         }
        
//         return true;
//     }
    
    // without any space
        // isalnum is an inbuilt function which check if its alphanumberic or not its in c and included in ctype.h header file
        
        int n=s.length();
        int i=0,j=n-1;
        
        while(i<j){
            while(i<j && !isalnum(s[i])){
                i++;
            }
            while(i<j && !isalnum(s[j])){
                j--;
            }
            if(tolower(s[i++])!=tolower(s[j--])) return false;
        }
        return true;
        
    }

    
};