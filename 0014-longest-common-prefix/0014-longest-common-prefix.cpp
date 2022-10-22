class Solution {
public:
    // brute force (mtlb solution optimal to h but clean ni h jo maine ye khud kia h to kuch clean bhi dekhna pdega)
//     string longestCommonPrefix(vector<string>& strs) {
        
        
        
//         string ans="";
//         if(strs.size()==1) return ans=strs[0];
//         string check="";
//         bool shi=false;
//         int j=0,k=0;
//         for(int i=0;i<strs.size()-1;i++){
//             string store1=strs[i];      // flower
//             string store2=strs[i+1];    // flow
//             j=store1.length();
//             k=store2.length();
//             if(k<j){
//                 for(k=0;k<store2.length();k++){
//                     if(store1[k]==store2[k]){
//                         check.push_back(store1[k]);
//                     }
//                     else break;
//                 }
//             }
//             else{
//                 for(j=0;j<store1.length();j++){
//                     if(store1[j]==store2[j]){
//                         check.push_back(store1[j]);
//                     }
//                     else break;
//                 }
//             }
//             if(shi==false){
//                 ans=check;
//                 shi=true;
//                 check="";
//             }
//             else{
//                 if(check.empty()) return check;
//                 else if(check.length()<ans.length()){
//                     ans=check;
//                     check="";
//                 }
//                 else check="";
//             }
//         }
//         return ans;
//     }
    
//     The longest common prefix is common to all the strings. So, we can fix one string and check the common prefix of this string with other strings. The minimum such length is found and the answer is the substring of the fixed string starting from 0 to the length of the above such minimum.
// Here, I have fixed 0th string and checked other strings with this.
// Full Code:

    string longestCommonPrefix(vector<string>& s) {
        int ans = s[0].length(), n = s.size();
        for(int i=1; i<n; i++){
            int j = 0;
            while(j<s[i].length() && s[i][j]==s[0][j])j++;
            ans = min(ans, j);
        }
        return s[0].substr(0, ans);
    }
};