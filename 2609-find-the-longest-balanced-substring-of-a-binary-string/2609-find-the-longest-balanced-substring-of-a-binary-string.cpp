class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans=0,count=0,c0=0,c1=0;
        
        int n=s.length()-1;
        
        while(n>=0){
            if(s[n]=='1'){
                c1++;
            }
            else if(s[n]=='0'){
                c0++;
            }
            if(s[n]=='0' && (n==0 || s[n-1]=='1' )){
                count=min(c0,c1);
                ans=max(ans,2*count);
                c0=0;c1=0;
            }
            n--;
        }
        return ans;
    }
};