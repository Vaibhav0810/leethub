class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int>v1(10,0);
        string s = to_string(n);
        for(int i=0;i<s.size();i++){
            v1[s[i]-'0']++;
        }
        // for(auto it:mp1) cout<<it.first;
        s.clear();
        vector<int>v2(10,0);
        long long store=1;
        for(long long i=0;i<50;i++){
            store=pow(2,i);
            s=to_string(store);
            for(int i=0;i<s.size();i++){
                v2[s[i]-'0']++;
            }
            if(v1==v2) return true;
            s.clear();
            v2.assign(10, 0);
        }

        return false;
    }
};