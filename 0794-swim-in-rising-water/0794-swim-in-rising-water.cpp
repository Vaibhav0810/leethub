class Solution {
public:
    vector<vector<int>> direc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> mat(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({grid[0][0], {0, 0}});
        mat[0][0] = grid[0][0];

        while (!pq.empty()) {
            auto top = pq.top();
            int wt = top.first;
            int row = top.second.first;
            int col = top.second.second;
            pq.pop();
            if (wt > mat[row][col])
                continue;

            for (int i = 0; i < 4; i++) {
                int nrow = row + direc[i][0];
                int ncol = col + direc[i][1];

                if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0) {
                    int nwt = max(wt, grid[nrow][ncol]);
                    if (nwt < mat[nrow][ncol]) {
                        pq.push({nwt, {nrow, ncol}});
                        mat[nrow][ncol] = nwt;
                    }
                }
            }
        }

        return mat[n - 1][m - 1];
    }
};