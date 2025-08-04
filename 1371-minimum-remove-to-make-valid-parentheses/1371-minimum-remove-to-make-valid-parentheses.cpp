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
    // as we know there will be only lower case letter and brackets so we can
    // mark extra bracket by a *
    //  and then remove it
    // string minRemoveToMakeValid(string s) {
    //     int n=s.length();
    //     string ans="";
    //     int count=0;
    //     for(int i=0;i<n;i++){
    //         if(s[i]=='('){
    //             count++;
    //         }
    //         if(s[i]==')') count--;
    //         if(count<0) s[i]='*',count++;
    //     }
    //     if(count>0){
    //         count=0;
    //         for(int i=n-1;i>=0;i--){
    //             if(s[i]=='(') count--;
    //             if(s[i]==')') count++;
    //             if(count<0) s[i]='*',count++;
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         if(s[i]!='*') ans.push_back(s[i]);
    //     }
    //     return ans;

    // }

    // instead of * placeholder we can use a bool vector array
    // bcoz if there are these chars too with alphabets then it will give
    // problem

    // string minRemoveToMakeValid(string s) {
    //     int n = s.length();
    //     vector<bool> valid(n, true);
    //     int count = 0;

    //     // Forward pass: remove extra ')'
    //     for (int i = 0; i < n; i++) {
    //         if (s[i] == '(') {
    //             count++;
    //         } else if (s[i] == ')') {
    //             if (count == 0) {
    //                 valid[i] = false; // Mark for removal
    //             } else {
    //                 count--;
    //             }
    //         }
    //     }

    //     // Backward pass: remove extra '('
    //     count = 0;
    //     for (int i = n - 1; i >= 0; i--) {
    //         if (s[i] == ')') {
    //             count++;
    //         } else if (s[i] == '(') {
    //             if (count == 0) {
    //                 valid[i] = false; // Mark for removal
    //             } else {
    //                 count--;
    //             }
    //         }
    //     }

    //     // Build the result
    //     string ans;
    //     for (int i = 0; i < n; i++) {
    //         if (valid[i]) {
    //             ans += s[i];
    //         }
    //     }
    //     return ans;
    // }

    //  STack version

      string minRemoveToMakeValid(string s) {
        stack<int> st;
        
        // First pass: track invalid parentheses
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop();
                } else {
                    st.push(i);
                }
            }
        }

        // Second pass: build the result in reverse, skipping invalid indices
        string result;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (!st.empty() && st.top() == i) {
                st.pop();
                continue;
            }
            result += s[i];
        }

        reverse(result.begin(), result.end());
        return result;
    }

};