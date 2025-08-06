class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int bfs(vector<vector<char>>& maze, vector<vector<int>>& visi, int row,
            int col) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int count = 0;
        pq.push({0,{row, col}});
        while (!pq.empty()) {
            auto st = pq.top();
            int wt = st.first;
            row = st.second.first;
            col=st.second.second;
            pq.pop();
            for (auto it : directions) {
                int nr = row + it[0];
                int nc = col + it[1];
                if (nr >= 0 && nc >= 0 && nr < maze.size() &&
                    nc < maze[0].size()) {
                    if (maze[nr][nc] != '+' && visi[nr][nc] != 1) {
                        visi[nr][nc] = 1;
                        // count++;
                        pq.push({wt+1,{nr, nc}});
                        if (nr == 0 || nc == 0 || nr == maze.size()-1 ||
                            nc == maze[0].size()-1)
                            return wt+1;
                    }
                }
            }
        }
        return -1;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> visi(n, vector<int>(m, 0));
        visi[entrance[0]][entrance[1]] = 1;
        return bfs(maze, visi, entrance[0], entrance[1]);
    }
};