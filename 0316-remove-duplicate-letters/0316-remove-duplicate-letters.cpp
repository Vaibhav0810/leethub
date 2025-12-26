class Solution {
public:
    string removeDuplicateLetters(string s) {
        // vector<int>freq(26,0);
        // for(auto it:s){
        //     freq[it-'a']++;
        // }
        // stack<char>st;
        // for(int i=0;i<s.size();i++){
        //     while(!st.empty() && st.top()>s[i] && freq[st.top()-'a']>0){
        //         st.pop();
        //     }
        //     st.push(s[i]);
        //     freq[s[i]-'a']--;
        // }
        // string ans = "";
        // while(!st.empty()){
        //     ans+=st.top();
        //     st.pop();
        // }
        // reverse(ans.begin(),ans.end());
        // set<char>se;
        // string ans2="";
        // for(auto it:ans){
        //     if(se.find(it)==se.end()){
        //         ans2+=it;
        //     }
        //     se.insert(it);
        // }
        // return ans2;

        vector<int>last(26,0);
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
        }
        vector<bool>seen(26,0);
        stack<char>st;
        for(int i=0;i<s.size();i++){
            while(!st.empty() && !seen[s[i]-'a'] && st.top()>s[i] && last[st.top()-'a']>i){
                seen[st.top()-'a']=0;
                st.pop();
            }
            if(!seen[s[i]-'a']){
            st.push(s[i]);
            seen[s[i]-'a']=1;
            }
        }

        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;


    }
};