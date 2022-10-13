class Solution {
public:
    int longestPalindrome(string s) {
        //"zeusnilemacaronimaisanitratetartinasiaminoracamelinsuez"
        // iss vale mei buffer overflow aa rha h
        
        // int store[57]={0};
        // for(int i=0;i<s.length();i++){
        //     store[s[i]-65]++;
        // }
        // int maxodd=INT_MIN;
        // int ans=0;
        // for(int i=0;i<57;i++){
        //     if(store[i]%2==0){
        //         ans=ans+store[i];
        //     }
        //     else{
        //         if(maxodd<store[i]) maxodd=store[i];
        //     }
        // }
        // if(maxodd!=INT_MIN) return ans+maxodd;
        // return ans;
        
        // iska logic ye hoga ki ans mei sare even ki freq dalo + odd-1 + 1 
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        int ans=0;
        bool oddpresent=false; // to check if odd hi there 
        for(auto it:mp){
            if(it.second%2==0) ans+=it.second;
            else{
                ans+=it.second-1;
                oddpresent=true;
            }
        }
        if(oddpresent==true)
        return ans+1;
        return ans;
    }
};