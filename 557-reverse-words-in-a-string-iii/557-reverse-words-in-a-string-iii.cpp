class Solution {
public:
    // brute
    
//     string reverseWords(string s) {
//         s.push_back(' ');
//         stack<char>st;
//         string ans="";
//         string a="";
//         for(int i=0;i<s.length();i++){
//             if(s[i]!=' '){
//                 st.push(s[i]);
//             }
//             else{
//                 while(!st.empty()){
//                     ans.push_back(st.top());
//                     st.pop();
//                 }
                
//                 a=a+ans;
//                 a.push_back(' ');
//                 ans="";
//             }
//         }
//         a.pop_back();
//         return a;
        
//    }
    
    // optimised  two pointer
    // space- O(1)
    string reverseWords(string s){
        int i=0;
        int j=0;
        string ans;
        s.push_back(' ');
        for(int k=0;k<s.length();k++){
            if(s[k]!=' '){
                ans.push_back(s[k]);
                j++;
            }
            else{
                j--;
                while(i<j){
                    char temp=ans[i];
                    ans[i]=ans[j];
                    ans[j]=temp;
                    i++;
                    j--;
                }
                ans.push_back(' ');
                
                i=k+1;
                j=k+1;
            }
        }
        ans.pop_back();
        return ans;
        
    }
    
};