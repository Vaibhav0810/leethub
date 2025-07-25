class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<int>result(n+1,INT_MAX);
        result[0]=0;
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        result[k]=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int node = top.second;
            int wt = top.first;
            for(auto it:adj[node]){
                int currWt=it.second;
                int adjNode = it.first;
                if(wt+currWt<result[adjNode]){
                    result[adjNode]=wt+currWt;
                    pq.push({result[adjNode],adjNode});
                }
            }
        }
        int ans= 0;
        for(auto it:result){
            if(it==INT_MAX) return -1;
            ans=max(it,ans);
        }
        return ans;
    }
};