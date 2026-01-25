class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp1;
        mp1.insert({'I',1});
        mp1.insert({'V',5});
        mp1.insert({'X',10});
        mp1.insert({'L',50});
        mp1.insert({'C',100});
        mp1.insert({'D',500});
        mp1.insert({'M',1000});
        int ans = 0;
        char prv = s[0];

        for(int i=0;i<s.length();){
            char f = s[i];
            char l = s[i+1];
            if(mp1[l]>mp1[f]){
                ans+=mp1[l]-mp1[f];
                i+=2;
            }
            else{
                ans+=mp1[f];
                i++;
            }
        }
        
        // int prvv = mp1.find(prv)->second;
        // for(int i=1;i<s.length();i++){
        //     char cur=s[i];
        //     int curr = mp1.find(cur)->second;
        //     if(curr>prvv) {
        //         curr-=prvv;
        //     ans+=curr;
        //     }
        //     else{
        //         ans+=prvv;
        //     }
        //     prv = s[i];
        //     prvv=mp1.find(prv)->second;

        // }
        return ans;

    }
};