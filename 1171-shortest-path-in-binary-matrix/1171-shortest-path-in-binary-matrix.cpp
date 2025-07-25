class Solution {
public:
    vector<vector<int>> directions{{1, 1},  {1, 0},  {0, 1},   {-1, 0},
                                   {0, -1}, {1, -1}, {-1, -1}, {-1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int V = grid.size();
        queue<pair<int, int>> q;
        if (grid[0][0] == 1 || grid[V - 1][V - 1] == 1)
            return -1;
        q.push({0, 0});
        grid[0][0] = 1;
        int count = 0;
        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                auto curr = q.front();
                q.pop();
                int row = curr.first;
                int col = curr.second;
                if(row==V-1 && col ==V-1) return count+1;
                for (auto dir : directions) {
                    int nr = dir[0];
                    int nc = dir[1];

                    if (row + nr >= 0 && row + nr < V && col + nc >= 0 &&
                        col + nc < V) {
                        if (grid[row + nr][col + nc] == 0) {
                            grid[row + nr][col + nc] = 1;
                            q.push({row + nr, col + nc});
                        }
                    }
                }
                
            }
            count++;
        }
        return -1;
    }
};