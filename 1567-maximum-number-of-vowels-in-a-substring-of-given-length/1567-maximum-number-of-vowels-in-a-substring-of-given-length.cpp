class Solution {
public:

    bool check(char c){
        if(c == 'a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int i=0,j=0,n=s.length(),length=0,ans=0;
        while(j<k){
            if(check(s[j])) length++;
            j++;
        }
        ans=length;
        j--;

        while(i<n && j<n){
            if(check(s[i])) length--;
            j++;
            i++;
            if(check(s[j])) length++;
            ans=max(ans,length);
        }
        return ans;


    }
};