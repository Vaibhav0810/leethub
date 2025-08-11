class Solution {
public:
    const long long MOD = 1000000007;

long long modPow(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> powers;
    for (int i = 30; i >= 0; i--) {
        if ((1 << i) <= n) {
            n -= (1 << i);
            powers.push_back(1 << i);
        }
    }
    reverse(powers.begin(), powers.end());

    vector<long long> preMul;
    long long store = 1;
    for (auto it : powers) {
        store = (store * it) % MOD;
        preMul.push_back(store);
    }

    vector<int> ans;
    for (auto& q : queries) {
        int l = q[0], r = q[1];
        long long result = preMul[r];
        if (l > 0) {
            // Multiply by modular inverse
            result = (result * modPow(preMul[l - 1], MOD - 2)) % MOD;
        }
        ans.push_back((int)result);
    }
    return ans;
}

};