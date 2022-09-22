class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        stack<char>st;
        string ans="";
        string a="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                st.push(s[i]);
            }
            else{
                while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }
                
                a=a+ans;
                a.push_back(' ');
                ans="";
            }
        }
        a.pop_back();
        return a;
        
    }
};