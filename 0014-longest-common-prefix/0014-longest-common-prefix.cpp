class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        
        
        string ans="";
        if(strs.size()==1) return ans=strs[0];
        string check="";
        bool shi=false;
        int j=0,k=0;
        for(int i=0;i<strs.size()-1;i++){
            string store1=strs[i];      // flower
            string store2=strs[i+1];    // flow
            j=store1.length();
            k=store2.length();
            if(k<j){
                for(k=0;k<store2.length();k++){
                    if(store1[k]==store2[k]){
                        check.push_back(store1[k]);
                    }
                    else break;
                }
            }
            else{
                for(j=0;j<store1.length();j++){
                    if(store1[j]==store2[j]){
                        check.push_back(store1[j]);
                    }
                    else break;
                }
            }
            if(shi==false){
                ans=check;
                shi=true;
                check="";
            }
            else{
                if(check.empty()) return check;
                else if(check.length()<ans.length()){
                    ans=check;
                    check="";
                }
                else check="";
            }
        }
        return ans;
    }
};