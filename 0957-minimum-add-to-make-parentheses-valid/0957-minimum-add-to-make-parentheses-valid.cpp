class Solution {
public:

    // in this we will calculate how many open are there and how many close are there 
    // and if open is greater than 0 and we find close we will minus it bcoz its a valid pair
    // if open is already 0 then we are gonna need that much open as we have close so we will increament close and return open and close sum;\

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