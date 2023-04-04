class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        
        int maxi=0;
        unordered_map<char,int>mp;
        int val=0;
        for(int i=0;i<chars.size();i++){
            mp[chars[i]]=i;
        }
        
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                val+=s[i]-97+1;
            }
            else{
                val+=vals[mp[s[i]]];
            }
            if(val<0) val=0;
            maxi=max(maxi,val);

            
        }
        return maxi;
    }
};