class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            if(s[i]==')'){
                int start=st.top();
                reverse(s.begin()+start,s.begin()+i);
                st.pop();
            }
        }
        string ans="";
        for(auto it:s){
            if(it=='('||it==')'){}
            else ans.push_back(it);
        }
        return ans;
    }
};