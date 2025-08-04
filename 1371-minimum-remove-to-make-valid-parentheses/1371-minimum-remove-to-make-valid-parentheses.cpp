class Solution {
public:
    // Time - O(k.n) where k is the number of invalid paranthesis Space O(1)
    // In this we will check if ) exceeds ( this count then erase
    // then in other pass we will check if ( exceeds ) this count then erase

    // string minRemoveToMakeValid(string s) {
        // int count = 0;
        // int idx = 0;
        // while (idx < s.length()) {
        //     if (s[idx] == '(')
        //         count++;
        //     if (s[idx] == ')')
        //         count--;

        //     if ((s[idx] == ')' || s[idx] == '(') && count < 0) {
        //         s.erase(s.begin() + idx);
        //         count++;
        //         idx--;
        //     }
        //     idx++;
        // }
        // idx = s.length()-1;
        // if (count > 0) {
        //     count = 0;
        //     while (idx >=0) {
        //         if (s[idx] == '(')
        //             count--;
        //         if (s[idx] == ')')
        //             count++;

        //         if ((s[idx] == ')' || s[idx] == '(') && count < 0) {
        //             s.erase(s.begin() + idx);
        //             count++;
        //         }
        //         idx--;
        //     }
        // }
        // return s;
    // }

    // Time - > O(N) Space O(N)
    // as we know there will be only lower case letter and brackets so we can mark extra bracket by a *
    //  and then remove it
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        string ans="";
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
            }
            if(s[i]==')') count--;
            if(count<0) s[i]='*',count++;
        }
        if(count>0){
            count=0;
            for(int i=n-1;i>=0;i--){
                if(s[i]=='(') count--;
                if(s[i]==')') count++;
                if(count<0) s[i]='*',count++;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]!='*') ans.push_back(s[i]);
        }
        return ans;

    }
};