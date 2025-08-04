class Solution {
public:

    // Time - O(N), Space - O(N)
    // isme hme jb bhi bigger element milega hm usse stack se pop kr denge n k-- kr denge
    // firr bhi agr k = 0 ni hua to end se pop krna shuru kr denge
    // then ans ko ans mei store krke return

    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.length();
        int i = 0;
        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        // to check aage ke zeroes
        while (ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i);
        // if string is empty return 0 or else return the string
        return ans.empty() ? "0" : ans;
    }
};