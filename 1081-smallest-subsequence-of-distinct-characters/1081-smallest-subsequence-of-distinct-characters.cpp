class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>last(26,-1);
        vector<bool>present(26,0);
        stack<int>st;

        for(int i=s.length()-1;i>=0;i--){
            if(last[s[i]-'a']==-1) last[s[i]-'a']=i;
        }

        for(int i=0;i<s.length();i++){
            while(!st.empty() && s[st.top()]>s[i] && present[s[i]-'a']==0 && last[s[st.top()]-'a']>i){
                present[s[st.top()]-'a']=0;
                st.pop();
            }
            if(!present[s[i]-'a']){
            st.push(i);
            present[s[i]-'a']=1;
            }
        }

        // for(auto it:last) cout<<it;
        string ans="";
        while(!st.empty()){
            ans.push_back(s[st.top()]);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};