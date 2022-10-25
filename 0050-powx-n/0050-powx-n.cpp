class Solution {
public:
//     long double myPow(double x, int n) {
//         if(x==0) return 0;
//         if(x==1) return 1;
//         if(n==0) return 1;
//         long double ans=1;
//         bool negative=false;
//         if(n<0) negative=true;
//         n=abs(n);
//         if(n%2==0){
//             for(int i=1;i<=n/2;i++){
//                 ans=ans*x;
//             }
//             if(negative==true) return 1/(ans*ans);
//             else return ans*ans;
//         }
//         else{
//             n=n-1;
//             for(int i=1;i<=n/2;i++){
//                 ans=ans*x;
//             }
//             if(negative ==true) return 1/(ans*ans*x);
//             return ans*ans*x;
//         }
        
//     }
    //. https://leetcode.com/problems/powx-n/discuss/739646/C%2B%2B-Iterative-vs.-Recursive-Bitwise-Solutions-Explained-100-Time-80-space
    double myPow(double x, int n){
        double res=1;
        while(n){
        if(n%2){
            if(n>0){
                res=res*x;
            }
            else{
                res=res/x;
            }
        }
            x=x*x;
            n=n/2;
        
        
        }
        return res;
    }
};