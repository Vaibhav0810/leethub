class Solution {
public:
    // topo sort

    void topoSort(int& count, vector<vector<int>>& adj, vector<int>& visi,
             vector<int>& ans, vector<int>& indegree) {
        queue<int> q;
        for (int i = 0; i < visi.size(); i++) {
            if (indegree[i] == 0)
                q.push(i), count++;
        }
        while (!q.empty()) {
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for (auto it : adj[x]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it), count++;
            }
        }
        return;
    }

    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        vector<int> visi(V, 0);
        vector<int> indegree(V, 0);
        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        vector<int> ans;
        stack<int> st;
        int count = 0;
        topoSort(count, adj, visi, ans, indegree);
        if (count == V)
            return ans;
        else
            return {};
    }
};