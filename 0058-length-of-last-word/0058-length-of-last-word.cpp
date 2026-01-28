class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length()-1;
        while(s[n]==' ') n--;
        int ans = 0;
        while(n>=0 && s[n]!=' '){
            ans++;
            n--;
        }
        return ans;
    }
};