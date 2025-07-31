class Solution {
public:

    // Approach - 1 Time - > O(M*N) 
    // isme hm brr brr part dhund rhe h string mei to hm tb tk traverse kr rhe h jb tk sare part remove ni ho jaate

    // string removeOccurrences(string s, string part) {
    //     while(s.length()> 0 && s.find(part)< s.length()){
    //         s.erase(s.find(part), part.length());
    //     }
    //     return s;
    // }

    // Approach - 2 Time - > O(M*N) Space -> O(M)
    // intuition stack mei push krte rho jaise hi element mile jo part string ke last ke equal h tb ulta traverse kro aur dekho ki agr pura remove ho gya to shi nhi to 1 temp mei daal do aur vps stack mei daal do

    // string removeOccurrences(string s, string part) {
    //     int i=0,n=s.length();
    //     int j=0,m=part.length();
    //     j=m-1;
    //     string ans="";
    //     stack<char>st;
    //     while(i<n){
    //         st.push(s[i]);
    //         i++;
    //         j=m-1;
    //         if(!st.empty() && st.top()==part[j]){
    //             string temp="";
    //             while(!st.empty() && j>=0 && temp.size()<=m && st.top()==part[j]){
    //                 temp.push_back(st.top());
    //                 st.pop();
    //                 j--;
    //             }
    //             if(temp.size()==m){
    //                 temp="";
    //             }
    //             else{
    //                 reverse(temp.begin(),temp.end());
    //                 for(auto it:temp) st.push(it);
    //             }

    //         }
    //     }
    //     while(!st.empty()) ans.push_back(st.top()), st.pop();
    //     reverse(ans.begin(),ans.end());
    //     return ans;
    // }

    // Approach 2 (Optimised) Same time and space

    // isme hm jaise hi stack ki length == part length tb hm usse ik dusre stack mei copy kr denge aur firr check krenge part h ya nhi h to remove ni to kuch ni

//  bool check(stack<char>& st, string& part, int n) {
//         stack<char> tempSt = st;

//         for(int idx = n-1; idx >= 0; idx--) {
//             if(tempSt.top() != part[idx]) {
//                 return false;
//             }

//             tempSt.pop();
//         }

//         return true;
//     }


//     string removeOccurrences(string s, string part) {
//         stack<char> st;

//         int m = s.length();
//         int n = part.length();

//         for(int i = 0; i < m; i++) {
//             st.push(s[i]);

//             if(st.size() >= n && check(st, part, n) == true) {
//                 for(int j = 0; j < n; j++) {
//                     st.pop();
//                 }
//             } 
//         }

//         string result = "";
//         while(!st.empty()) {
//             result.push_back(st.top());
//             st.pop();
//         }

//         reverse(begin(result), end(result));
//         return result;
//     }
// };

    
    //Approach-3 (Using string as a stack)
    //T.C : O(m*n)
    //S.C : O(1), not considering result as extra space

    // in this we wont use any stack instead use string as a stack so we will push in it if its length is greater than or equal to part we will check that length substr and if matches then we will erase it

    string removeOccurrences(string s, string part) {
        string result = "";
        int n = part.length();

        for(char &ch : s) {
            result.push_back(ch);

            if(result.length() >= n && result.substr(result.length() - n) == part) {
                result.erase(result.length() - n);
            }
        }

        return result;
    }

};