class Solution {
public:

    string expand(int i,int j, string s){
        while(i>=0 && j<s.length() && s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }

    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0;i<s.length();i++){
            string odd = expand(i,i,s);

            if(odd.length()>ans.length()) ans=odd;

            string even = expand(i,i+1,s);
            if(even.length()>ans.length()) ans=even;
        }

        return ans;
    }
};