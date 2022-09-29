
class Solution {
public:
    // ye not working long test cases mei problem aa rhi h kuch pta ni kyu
    
//     vector<int> plusOne(vector<int>& digits) {
//         vector<int>ans(digits.size()+1,0);
//         ll num=0,n=digits.size()-1;
//         for(ll i=0;i<digits.size();i++){
//             num=num+(digits[i]*pow(10,n));
//             n--;
//         }
//         num=num+1;
//         ll i=digits.size();
//         while(num>0){
//             ll x=num%10;
//             ans[i]=x;
//             num=num/10;
//             i--;
//         }
        
//         if(ans[0]==0) {
//             ans.erase(ans.begin());
//             }
        
//         return ans;
        
//     }
    
    vector<int> plusOne(vector<int>& digits){
        vector<int>ans(digits.size()+1,0);
        
        int n=digits.size();
        digits[n-1]=digits[n-1]+1;
        int j=ans.size()-1;
        for(int i=n-1;i>=0;i--){
            
            if(digits[i]==10){
                digits[i]=0;
                ans[j]=digits[i];
                if(i-1>-1){
                    digits[i-1]=digits[i-1]+1;
                }
                else ans[j-1]=1;
                j--;
            }
            else {
                ans[j]=digits[i];
                j--;
                }
        }
        if(ans[0]==0) ans.erase(ans.begin());
        return ans;
    }
    
};