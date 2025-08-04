class Solution {
public:
    // Time - O(N^2) Space - O(N)
    // string reverseParentheses(string s) {
    //     stack<int>st;
    //     for(int i=0;i<s.size();i++){ // O(N)
    //         if(s[i]=='(') st.push(i);
    //         if(s[i]==')'){
    //             int start=st.top();
    //             reverse(s.begin()+start,s.begin()+i); //O(N)
    //             st.pop();
    //         }
    //     }
    //     string ans="";
    //     for(auto it:s){
    //         if(it=='('||it==')'){}
    //         else ans.push_back(it);
    //     }
    //     return ans;
    // }

    // Time - O(N) Space -O(N)
    // isme hm open and close brackets ke pair bna lenge
    // eg (u(love)i)
    //    0 2    7 9
    // 0->9
    // 2->7
    // to jb bhi bracket aaega hm usse uske pair pr fekk denge and keep on changing its direction of movig
    // so it will work like this
    // 0->9 i
    // 7->2 love
    // 7->2 u (rev direction)
     string reverseParentheses(string s) {
        int n = s.length();
        stack<int> openBracket;
        vector<int> door(n);

        // First pass: Pair up parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                openBracket.push(i);
            } else if (s[i] == ')') {
                int j = openBracket.top();
                openBracket.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        // Second pass: Build the result string
        string result;
        int direction = 1; //Left to Right
        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = door[i];
                direction = -direction;
            } else {
                result += s[i];
            }
        }
        return result;
    }
};