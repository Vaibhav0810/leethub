class Solution {
public:
    int minSwaps(string s) {
        char open='[',close=']';
        int i=0,j=0,n=s.length();
        int openL=0;
        stack<char>st;
        if(s[0]==open) openL++;
        st.push(s[0]);
        i++;
        while(i<n){
            if(!st.empty() && st.top()==open && s[i]==close){
                st.pop();
                openL--;
            }
            // else if(!st.empty() && st.top()==close && s[i]==open)
            else{
                if(s[i]==open) openL++;
                st.push(s[i]);
            }
            i++;
        }
        return (int)((openL+1)/2);
    }
};