class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i=0,n=s.length();
        int j=0,m=part.length();
        j=m-1;
        string ans="";
        stack<char>st;
        while(i<n){
            
            st.push(s[i]);
            i++;
            j=m-1;
            if(!st.empty() && st.top()==part[j]){
                string temp="";
                while(!st.empty() && j>=0 && st.top()==part[j]){
                    temp.push_back(st.top());
                    st.pop();
                    j--;
                }
                if(temp.size()==m){
                    temp="";
                }
                else{
                    reverse(temp.begin(),temp.end());
                    for(auto it:temp) st.push(it);
                }

            }
        }
        while(!st.empty()) ans.push_back(st.top()), st.pop();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};