class Solution {
public:
    long long mySqrt(int x) {
        // brute
        // for(long long i=1;i<1000000;i++){
        //     if(i*i==x){
        //         return i;
        //     }
        //     else{
        //         if(((i*i)<x) && ((i+1)*(i+1)>x)){
        //             return i;
        //         } 
        //     }
        // }
        // return 0;
        
        //optimal (newton method)
        
        if(x==0) return 0;
        
        long r=x;
        while(r*r>x){
            r=(r+x/r)/2;
        }
        return r;
        
    }
};