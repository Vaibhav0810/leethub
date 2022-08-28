class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<char>st1;
        string ans;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                
                while(st1.top()!='('){
                    ans.push_back(st1.top());
                    st1.pop();
                }
                st1.pop();
                
                
                for(int j=0;j<ans.length();j++){
                    st1.push(ans[j]);
                }
                    ans.clear();
                
                
            }
            else{
                st1.push(s[i]);
            }
        }
        
        while(!st1.empty()){
            ans.push_back(st1.top());
            st1.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};