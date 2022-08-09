// #define long long int
class Solution {
public:
    // isme tu kuch bhi krle ye ni chl rha 10 ke bdd overflow hoga
    /*
    long long unsigned fact(long long unsigned n){
        int mod=1e+7;
        long long unsigned prod=1;
        while(n>0){
            prod=prod*n;
            n--;
        }
        return prod;
    }
    int numTrees(int n) {
        int mod=1e+7;
        long long unsigned x=fact(2*n);
        long long unsigned y=fact(n+1);
        long long unsigned z=fact(n);
        long long unsigned ans=x/(y*z);
        // cout<<ans;
        return ans;
    }
    */
    
    // catlan eq se krenge
    // brute force TLE time comp = O(3^N)
    // int numTrees(int n){
    //     if(n<=1) return 1; // bcoz t(0) and t(1) =1
    //     int ans=0;
    //     for(int i=1;i<=n;i++){
    //         ans=ans+numTrees(i-1)*numTrees(n-i);
    //     }
    //     return ans;
    // }
    
    //catlan number in other form
    // time com=O(N) space = O(1)
    // ye bhi ni chll rha 14 ke upr tle
//     long long unsigned help(int n,int r){
//         long long unsigned prod=1;
//         for(int i=0;i<n-r;i++){
//             prod=prod*(n-i);
//         }
//         return prod;
//     }
    
//     int numTrees(int n){
//         long long unsigned half=help(2*n,n+1);
//         long long prod=1;
//         while(n>0){
//             prod=prod*n;
//             n--;
//         }
//         return half/prod;
//     }
    
    // isme hmm sath sath divide kr rhe h jiss se prod chota rhe aur limit ke bhr na jaaye
    
    
    long long help(int n,int r){
        long long prod=1;
        for(int i=0;i<r;i++){
            prod=prod*(n-i);
            prod=prod/(i+1);
        }
        return prod;
    }
// ye end mei n+1 se iislie divide kr rhe h bcoz upr divide n tk hi ho rha h to isilie idhr bcha hua
    int numTrees(int n){
        return help(2*n,n)/(n+1);
    }
    
};