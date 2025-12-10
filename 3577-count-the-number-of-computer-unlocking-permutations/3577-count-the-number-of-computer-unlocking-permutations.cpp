class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mod =1e9+7;
        int n = complexity.size();
        int f = complexity[0];
        for(int i=1;i<n;i++){
            if(f>=complexity[i]) return 0;
        }


        long long ans = 1;

        for(int i=1;i<n;i++){
            ans = (ans*i)%mod;
        }


        return ans%mod;

    }
};