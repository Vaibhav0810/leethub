class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(i<s.length()-2 && s[i]==s[i+1] && s[i]==s[i+2]){
                
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};