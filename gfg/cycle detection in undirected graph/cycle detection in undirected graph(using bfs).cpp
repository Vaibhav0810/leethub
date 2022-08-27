class Solution{
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> visi(V,0);
        
        for(int i=0;i<V;i++){
            if(!visi[i]){
                if(help(i,V,visi,adj))return true;
            }
        }
        return false;
    }
    
    bool help(int node,int V,vector<int>& visi,vector<int> adj[]){
        
        queue<pair<int,int>>q;
        q.push({node,-1});
        visi[node]=1;
        while(!q.empty()){
        auto node=q.front().first;
        auto prv=q.front().second;
        q.pop();
        
        for(auto it:adj[node]){
            if(!visi[it]){
                visi[it]=1;
                q.push({it,node});
            }
            else if(prv!=it) return true;
        }
        }
        return false;
    }
};
