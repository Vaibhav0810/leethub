class Solution {
public:
    bool dfs(int u, int curr, vector<int>& color, int V,
             vector<vector<int>>& graph) {
        color[u] = curr;
        for (auto it : graph[u]) {
            if (color[it] == -1) {
                 if(!dfs(it, !curr, color, V, graph)) return false;
            } else {
                if (color[it] == color[u])
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(i, 1, color, V, graph) == false)
                    return false;
            }
        }
        return true;
    }
};