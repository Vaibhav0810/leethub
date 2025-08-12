class Solution {
public:
    bool dfs(int i, vector<vector<int>>& adj, vector<bool>& visi, vector<bool>& hasApple, int &count) {
        visi[i] = true;
        bool foundApple = hasApple[i];

        for (auto it : adj[i]) {
            if (!visi[it]) {
                if (dfs(it, adj, visi, hasApple, count)) {
                    count += 2; // cost to go to child and back
                    foundApple = true;
                }
            }
        }

        return foundApple;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visi(n, false);
        int count = 0;
        dfs(0, adj, visi, hasApple, count);
        return count;
    }
};