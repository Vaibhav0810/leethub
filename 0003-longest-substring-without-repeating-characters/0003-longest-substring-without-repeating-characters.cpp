class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        
        int n = s.length();
        set<char>st;
        int maxAns=0;
        while(r<n){
            if(st.find(s[r])==st.end()) { //nhi mila
                st.insert(s[r]);
                maxAns= max(maxAns, r-l+1);
                
            }
            else{
                
                while(l<r && st.find(s[r])!=st.end() ){

                    st.erase(s[l]);
                    l++;
                }
                st.insert(s[r]);
                maxAns= max(maxAns, r-l+1);
            }
            r++;
            
        
        }
        return maxAns;
    }
};