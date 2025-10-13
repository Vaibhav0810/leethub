class Solution {
public:

    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int maxFreq = 0;

            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                freq[idx]++;
                maxFreq = max(maxFreq, freq[idx]);

                bool balanced = true;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] != 0 && freq[k] != maxFreq) {
                        balanced = false;
                        break;
                    }
                }

                if (balanced) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};