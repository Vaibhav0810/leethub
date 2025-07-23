class Solution {
public:
    int V;
    void dfs(vector<vector<int>>& isConnected, vector<int>& visi, int i) {
        visi[i] = 1;
        for (int v = 0; v < V; v++) {
            if (!visi[v] && isConnected[i][v] == 1)
                dfs(isConnected, visi, v);
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        V = isConnected.size();
        // vector<vector<int>> adj(V);
        vector<int> visi(V, 0);

        // for (int i = 0; i < V; i++) {
        //     for (int j = i; j < V; j++) {
        //         if (i == j)
        //             continue;
        //         if (isConnected[i][j] != 0) {
        //             int u = i;
        //             int v = j;
        //             adj[u].push_back(v);
        //             adj[v].push_back(u);
        //         }
        //     }
        // }

        for (int i = 0; i < V; i++) {
            if (!visi[i]) {
                ans++;
                dfs(isConnected, visi, i);
            }
        }

        return ans;
    }
};