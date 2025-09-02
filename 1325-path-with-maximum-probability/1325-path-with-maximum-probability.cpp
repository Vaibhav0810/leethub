class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int dest) {
        vector<double>ans(n,0);

        vector<vector<pair<int,double>>>adj(n);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double wt = succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<pair<double,int>>pq;
        pq.push({1,src});
        // ans[src]=1;

        while(!pq.empty()){
            pair<double,int>top=pq.top();
            pq.pop();
            double currWt=top.first;
            int currNode=top.second;
            for(auto it:adj[currNode]){
                int adjNode=it.first;
                double adjWt=it.second;
                if(currWt*adjWt>ans[adjNode]){
                    ans[adjNode]=currWt*adjWt;
                    pq.push({ans[adjNode],adjNode});
                }
            }
        }

        return ans[dest];

    }
};