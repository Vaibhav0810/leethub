class Solution {
public:
    int minSwaps(string s) {
        //in this we know opening and closing tags count will be same so we will just take remove the matching pairs first then take the count of either opening/closing brackets and then count+1/2 will give us the ans(bcoz at one time 2 brackts are changed in case of swap)

        // char open='[',close=']';
        // int i=0,j=0,n=s.length();
        // int openL=0;
        // stack<char>st;
        // if(s[0]==open) openL++;
        // st.push(s[0]);
        // i++;
        // while(i<n){
        //     if(!st.empty() && st.top()==open && s[i]==close){
        //         st.pop();
        //         openL--;
        //     }
        //     else{
        //         if(s[i]==open) openL++;
        //         st.push(s[i]);
        //     }
        //     i++;
        // }
        // return (int)((openL+1)/2);

        // we can also do this in Space - > O(1)
        //just take count of opening brack and decrement if closing one is found then divide

        int stSize=0;
        int i=0,n=s.length();
        while(i<n){
            if(s[i]=='[') stSize++;
            else{
                if(stSize>0) stSize--;
            }
            i++;
        }
        return (stSize+1)/2;

    }
};