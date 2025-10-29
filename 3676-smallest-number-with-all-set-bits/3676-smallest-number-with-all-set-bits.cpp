class Solution {
public:
    int smallestNumber(int n) {
        // vector<int> v(11, 0);
        // while (n > 1) {
        //     int x = 0;
        //     int i = 0;
        //     while (x < n) {
        //         x = pow(2, i);
        //         i++;
        //     }
        //     i--;
        //     if (x == n) {
        //         v[i] = 1;
        //         n = n % x;
        //     } else {
        //         v[i - 1] = 1;
        //         int z = pow(2, i - 1);
        //         n = n % z;
        //     }
        // }
        // // for(auto it:v) cout<<it;
        // int ans = 0;
        // int store = 0;
        // for (int i = v.size() - 1; i >= 0; i--) {
        //     if (v[i] == 1) {
        //         store = i;
        //         break;
        //     }
        // }
        // // cout<<" "<<store;
        // while (store>=0) {
        //     ans = ans + pow(2, store);
        //     store--;
        // }
        // return ans;
        int x = 1;
        while(x<=n){
            x = x*2;
        }
        return x-1;

    }
};