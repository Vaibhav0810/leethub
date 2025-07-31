class Solution {
public:

    // in this i will keep pushing in stack until I get )
    // when i get this i will just keep popping the stack until i get &/ | / ! and keep on incrementing f and t.
    // now i will evaluate the statement and push it in stack

    bool parseBoolExpr(string exp) {
        int f =0,t=0,i=0,n=exp.length();
        if(n<=1) return exp[0]=='f' ? false:true;
        stack<char>st;
        int currF=0,currT=0;
        
        while(i<n){
            if(exp[i]==')'){ 
                while(st.top()!='&' && st.top()!='!' && st.top()!='|'){
                    if(st.top()=='f') f++;
                    if(st.top()=='t') t++;
                    st.pop();
                }
                if(st.top()=='&'){
                    st.pop();
                    if(f>0) st.push('f');
                    else if(t>0) st.push('t');
                }
                else if(st.top()=='|'){
                    st.pop();
                    if(t>0) st.push('t');
                    else st.push('f');
                }
                else{
                    st.pop();
                    if(t>0) st.push('f');
                    else st.push('t');
                }
                f=0;
                t=0;
            }
            
            st.push(exp[i]);
            i++;
        }
       
        st.pop();
        if(st.top()=='f') return false;
        return true;
    }
};