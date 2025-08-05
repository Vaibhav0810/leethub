class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int maxi=x>=y?x:y;
        stack<char>st;
        int ans=0;
        if(maxi==x){
            for(int i=0;i<s.size();i++){
                if(!st.empty() && st.top()=='a' && s[i]=='b') st.pop(),ans+=x;
                else st.push(s[i]);
            }
            
            s.clear();
            while(!st.empty()){
                s.push_back(st.top());
                st.pop();
            }
            reverse(s.begin(),s.end());
            for(int i=0;i<s.size();i++){
                if(!st.empty() && st.top()=='b' && s[i]=='a') st.pop(),ans+=y;
                else st.push(s[i]);
            }
        }
        else{
            for(int i=0;i<s.size();i++){
                if(!st.empty() && st.top()=='b' && s[i]=='a') st.pop(),ans+=y;
                else st.push(s[i]);
            }
            s.clear();
            while(!st.empty()){
                s.push_back(st.top());
                st.pop();
            }
            reverse(s.begin(),s.end());
            for(int i=0;i<s.size();i++){
                if(!st.empty() && st.top()=='a' && s[i]=='b') st.pop(),ans+=x;
                else st.push(s[i]);
            }

        }
        return ans;

    }
};