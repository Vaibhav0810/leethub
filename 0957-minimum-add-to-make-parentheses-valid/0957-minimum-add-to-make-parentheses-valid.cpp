class Solution {
public:

    // in this we will calculate how many open are there and how many close are there 
    // and just return their difference

    int minAddToMakeValid(string s) {
        int open=0,close=0;
        int i=0,n=s.length();
        while(i<n){
            if(s[i]=='(') open++; 
            else{
                if(open>0) open--;
                else close++;
            }
            i++;
        }
        return abs(open+close);
    }
};