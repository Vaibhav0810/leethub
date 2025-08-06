class Solution {
public:
    void dfs(int i, vector<vector<int>> adj, vector<int>&visi) {
        visi[i] = 1;
        for (auto it : adj[i]) {
            if (!visi[it])
                dfs(it, adj, visi);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                adj[i].push_back(rooms[i][j]);
            }
        }
        vector<int> visi(n, 0);
        dfs(0, adj, visi);
        for (auto it : visi) {
            cout<<it<<" ";
            if (it==0) {
                return false;
            }
        }
        return true;
    }
};