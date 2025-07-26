class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<int>inMST(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<V;i++){
            for(int j=1;j<V;j++){
                int u=i;
                int v=j;
                int w = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[u].push_back({v,w});
                adj[v].push_back({u,w});
            }
        }
        int sum=0;
        while(!pq.empty()){
            auto top=pq.top();
            int wt=top.first;
            int node=top.second;
            pq.pop();
            if(inMST[node]==1) continue;
            sum+=wt;
            inMST[node]=1;
            for(auto it:adj[node]){
                int neigh=it.first;
                int nWt=it.second;

                if(inMST[neigh]==0){
                    pq.push({nWt,neigh});
                }

            }
        }

        return sum;
    }
};