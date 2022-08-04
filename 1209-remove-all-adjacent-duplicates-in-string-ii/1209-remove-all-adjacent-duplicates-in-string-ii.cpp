class Solution {
public:
    string removeDuplicates(string s, int k) {
        
//        // https://assets.leetcode.com/users/images/b726226d-c917-4715-a1d2-a16a3abb6fad_1651809397.3889582.gif
        
//         Time Complexity :- O(N * K)

//         Space Complexity :- O(N)
        
        // isme phle 2 stack bnayenge master n helper
        // agr master khali hoga to phle helper mei push kr denge aur usse firr master mei daal denge firr helper khali kr denge 
        //
        // agr master khali ni h to aur uska top s[i] ke equal h to helper mei daal denge aur master khali kr denge
        // aur agr firr helper ka size =k ho jaata h to helper mei se k pop ni to vapas master mei
        
//         stack<char> master;
        
//         for(int i=0;i<s.length();i++){
//             stack<char> helper;
            
//             helper.push(s[i]);
//             while(!master.empty() && master.top()==s[i]){
//                 helper.push(master.top());
//                 master.pop();
//             }
            
//             if(helper.size()!=k){
//                 while(!helper.empty()){
//                     master.push(helper.top());
//                     helper.pop();
//                 }
//             }
            
//         }
//         string ans="";
//         while(master.size()!=0){
//             ans.push_back(master.top());
//             master.pop();
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
        
//         ✔️ Solution - II (Using Stack) (ye bekr approach h  can skip to next)

// We can observe that in the above appraoch, we re-iterating the string and rechecking for adjacent duplicates multiple times. This approach can be better understood with an example -

// let s = "abbccddeefffedcba"

// 1. We will iterate till last "f". Here, k adjacent duplicates are found. So we delete "fff" and iterate till end of the string.
// 2. Restart from beginning since deletion happened in previous loop.
// 3. We again iterate till last "e". we find "eee" and delete it and iterate till end of string.
// 4. Again restart from beginning.
// And so on..

// In above approach, we can see that we are doing multiple unnecessary checks. 
// We already know after deleting "fff" that previously we had "ee" and if next one is "e", we should delete that too.

// Thus, we use a stack to remember what we had previously, so we don't have to re-iterate from begin and recheck again and again.
// The implementation of above approach is given below -
        
//         stack<pair<char,int>>st;
        
//         st.push({'#',0});
        
//         for(int i=0;i<s.length();i++){
//             st.push({s[i],st.top().first==s[i]?st.top().second+1:1});
            
//             if(st.top().second==k){
//                 while(st.top().first==s[i]) st.pop();
//                 s.erase(i-k+1,k);
//                 i-=k;
//             }
            
//         }
            
//         return s;
     
        // best approach
        //https://assets.leetcode.com/users/images/ae0e8a46-5cb2-48f5-abac-cb6667ab0740_1651809424.86439.gif
        // using one stack and less run time than prv
        //Time Complexity :- O(N)

        //Space Complexity :- O(N)
        
        stack<pair<char,int>> master;
        
        for(int i =0;i<s.length();i++){
            if(!master.empty() && master.top().first==s[i]){
                master.top().second++;
            }
            else master.push({s[i],1});
            if(master.top().second==k){
                master.pop();
            }
        }
        string ans;
        while(!master.empty()){
            int top=master.top().second;
            while(top--){
                ans.push_back(master.top().first);
            }
            master.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};