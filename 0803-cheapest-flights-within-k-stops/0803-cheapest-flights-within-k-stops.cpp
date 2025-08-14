class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<int> dist(n, INT_MAX);
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }
        queue<pair<int,int>>q;
        q.push({src,0});
        dist[src]=0;
        int steps=0;

        while(!q.empty() && steps<=k){
            int N= q.size();

            while(N--){
                int u=q.front().first;
                int d=q.front().second;

                q.pop();
                for(auto P:adj[u]){
                    int v = P.first;
                    int cost = P.second;
                    if(dist[v] > d+cost){
                        dist[v]=d+cost;
                        q.push({v,d+cost});
                    }
                }
            }
            steps++;
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
        
    }
};