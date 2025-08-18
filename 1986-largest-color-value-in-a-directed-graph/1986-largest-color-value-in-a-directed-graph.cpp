class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<vector<int>> store(n, vector<int>(26, 0));

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                store[i][colors[i] - 'a'] = 1;
            }
        }
        int countNodes = 0;
        int ans = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            countNodes++;
            ans = max(ans, store[u][colors[u] - 'a']);

            for (int v : adj[u]) {
                for (int i = 0; i < 26; i++) {
                    store[v][i] =
                        max(store[v][i], store[u][i] + (colors[v] - 'a' == i));
                }
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        if (countNodes < n)
            return -1;
        return ans;
    }
};