class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int n = s.length();
        int maxAns=0;
        vector<int>mp1(256,-1);
        while(r<n){
            if(mp1[s[r]]!=-1){
                l=max(mp1[s[r]]+1,l);
            }
                mp1[s[r]]=r;
            
                maxAns=max(maxAns,r-l+1);
          
            r++;
            
        }
        return maxAns;
    }
};