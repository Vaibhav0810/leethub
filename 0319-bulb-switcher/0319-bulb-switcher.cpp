class Solution {
public:
    
    
    
    int bulbSwitch(int n) {
        if(n==0) return 0;
        int sum=1;
        
        for(long long i=2;i<=n/2;i++){
            long long prod=i*i; 
            if(prod<=n) sum++;
        }
        
        return sum;
    }
};