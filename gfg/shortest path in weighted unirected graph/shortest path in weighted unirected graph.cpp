
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        // doing dijksta algo and just pushing in the vector
        
        vector<pair<int,int>>adj[n+1];
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({u,w});
        }
        
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        vector<int>dist(n+1,1e9);
        dist[1]=0;
        pq.push({0,1}); //we node
        
        while(!pq.empty()){
            int node=pq.top().second;
            int weight=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int adjweight=it.second;
                if(dist[adjnode]>weight+adjweight){
                    dist[adjnode]=weight+adjweight;
                    //isme phle to dikstra algo lgakr ab hmne ik parent array bnaya h 
        // to phle usko khudki value se initialize kia ab dekh rhe h vo kha se aarha h
        // jha se aarha h udhr ki value uss mei push kr rhe h line42
                    parent[adjnode]=node;
                    pq.push({dist[adjnode],adjnode});
                }
            }
            
        }
        //isme phle to dikstra algo lgakr ab hmne ik parent array bnaya h 
        // to phle usko khudki value se initialize kia ab dekh rhe h vo kha se aarha h
        // jha se aarha h udhr ki value uss mei push kr rhe h line42
        //firr ab neeche aakr check kr rhe h ki agr end ki valie mei abhi bhi max value h 
        // mtlb vo udhr tk phucha nii to -1 return aur agr phuch gya to
        // vector pr back track krte jaao jb tk 1 pr na phch jaae aur vo ans
        
        if(dist[n]==1e9) return {-1};
        int node=n;
        while(parent[node]!=node){
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
