class Solution {
public:
    long long mySqrt(int x) {
        for(long long i=1;i<1000000;i++){
            if(i*i==x){
                return i;
            }
            else{
                if(((i*i)<x) && ((i+1)*(i+1)>x)){
                    return i;
                } 
            }
        }
        return 0;
    }
};