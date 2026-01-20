class Solution {
public:
    int findSum(int i, int j, int r2, int c2, vector<vector<int>>& pre) {
        return pre[r2][c2] - (i > 0 ? pre[i-1][c2] : 0) -
               (j > 0 ? pre[r2][j-1] : 0) +
               ((i > 0 && j > 0) ? pre[i-1][j-1] : 0);
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int ans = 0;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pre(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pre[i][j] = (i > 0 ? pre[i - 1][j] : 0) +
                            (j > 0 ? pre[i][j - 1] : 0) + mat[i][j] -
                            ((i > 0 && j > 0) ? pre[i - 1][j - 1] : 0);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < min(n - i, m - j); k++) {
                    int r2 = i + k, c2 = j + k;
                    int sum = findSum(i, j, r2, c2, pre);

                    if (sum <= threshold) {
                        ans = max(ans, k + 1);
                    } else
                        break;
                }
            }
        }
        return ans;
    }
};