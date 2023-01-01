class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char>mp1;
        
        
        int x=0;
        vector<string>v;
        string c="";
        while(x<s.size()){
            while(s[x]!=' ' && x<s.size()){
                c.push_back(s[x]);
                x++;
            }
            v.push_back(c);
            c.clear();
            x++; 
        }
        set<char>count;
        
          if (v.size() != pattern.size())
         {
          return false;
         }
        
        for(int i=0;i<pattern.size();i++){
            if(mp1.find(v[i])==mp1.end() && count.find(pattern[i])==count.end()){
                mp1.insert({v[i],pattern[i]});
                count.insert(pattern[i]);
            }
            else if(mp1[v[i]]!=pattern[i])
                return false;
        } 
        return true;
    }
};