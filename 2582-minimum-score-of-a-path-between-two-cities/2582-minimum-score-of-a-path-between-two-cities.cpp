class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        ///////// wt,    node
        pq.push({INT_MAX,0});
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u-1].push_back({v-1,w});
            adj[v-1].push_back({u-1,w});
        }

        while(!pq.empty()){
            auto prv=pq.top();
            pq.pop();
            int wt=prv.first;
            int node=prv.second;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int currwt=it.second;
                int miniwt=min(currwt,wt);
                if(dist[adjNode]>miniwt){
                dist[adjNode]=miniwt;
                pq.push({miniwt,adjNode});
                }
            }
        }
        return (dist[n-1]);
    }
};