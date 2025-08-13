class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        // vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        // ans[src] = {0, 0};
        pq.push({0, {src, 0}});
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto [currDist, state] = pq.top();
            auto [currNode, stops] = state;
            pq.pop();

            if (stops > k)
                continue;

            for (auto [node, d] : adj[currNode]) {
                int newCost = currDist + d;
                if (newCost < dist[node][stops + 1]) {
                    dist[node][stops + 1] = newCost;
                    pq.push({newCost, {node, stops + 1}});
                }
            }
        }

        int ansCost = INT_MAX;
        for (int s = 0; s <= k + 1; s++) {
            ansCost = min(ansCost, dist[dst][s]);
        }
        return (ansCost == INT_MAX) ? -1 : ansCost;
    }
};