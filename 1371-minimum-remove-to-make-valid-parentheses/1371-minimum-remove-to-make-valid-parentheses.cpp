class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;
        int idx = 0;
        // string ans="";
        while (idx < s.length()) {
            if (s[idx] == '(')
                count++;
            if (s[idx] == ')')
                count--;

            if ((s[idx] == ')' || s[idx] == '(') && count < 0) {
                s.erase(s.begin() + idx);
                count++;
                idx--;
            }
            // else ans.push_back(s[i]);
            idx++;
        }
        idx = s.length()-1;
        if (count > 0) {
            count = 0;
            while (idx >=0) {
                if (s[idx] == '(')
                    count--;
                if (s[idx] == ')')
                    count++;

                if ((s[idx] == ')' || s[idx] == '(') && count < 0) {
                    s.erase(s.begin() + idx);
                    count++;
                    // idx++;
                }
                // else ans.push_back(s[i]);
                idx--;
            }
        }
        return s;
    }
};