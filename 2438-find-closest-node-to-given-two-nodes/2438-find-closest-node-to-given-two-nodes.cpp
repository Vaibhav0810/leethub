class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<int>& dist) {
        int d = 0;
        while (node != -1 && dist[node] == -1) {
            dist[node] = d++;
            node = edges[node];
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        // Distance arrays for both starting nodes
        vector<int> dist1(n, -1), dist2(n, -1);

        // Run DFS/BFS-like traversal for both nodes
        dfs(node1, edges, dist1);
        dfs(node2, edges, dist2);

        // Find node that minimizes the maximum distance from both
        int ans = -1;
        int minDist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    ans = i;
                }
            }
        }

        return ans;
    }
};