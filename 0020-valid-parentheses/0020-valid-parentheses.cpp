class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        
        // phle dekhenge agr inn teeno mei se koi h to stack mei push krdo aaram se
        
        for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
            
            // agr aisa ni h to phle check kro ki stack khali to ni h (bcoz agr aisa test case hoga to error dega '}')
            // firr check kro ki jo stack ke top pr h aur jo s[i] h vo pair h ya ni agr h to pop krdo 
            // ni h to return false
            
            // end mei check krna h agr stack empty h to true return krdo ni to false ye islie bcoz 
            // end mei agr aisa kuch aajata h ('(') aur iska pair bhi ni bnega ye khali rhega too ye bhi valid ni h

        else{
            if(st.empty()|| (st.top()=='(' && s[i]!=')') || (st.top()=='{' && s[i]!='}') || (st.top()=='[' && s[i]!= ']') )
                return false;
            st.pop();
        }
            
      }
        return st.empty();
    }
};