class Solution {
public:
    // bool isPowerOfThree(int n) {
    //     for(int i=0;i<n;i++){
    //         if(pow(3,i)==n) return true;
    //         else if(pow(3,i)>n) return false;
    //     }
    //     return false;
    // }
    // doing it without pow
    // follow up solve without loops/ recursion
    bool isPowerOfThree(int n){
        if(n<=0) return false;
        while(n>1){
            if(n%3!=0) return false;
            else{
                n=n/3;
            }
        }
        return true;
    }
    
};