class Solution {
public:

    void dfs(int i,vector<int>&visi,vector<vector<int>>& adj,int n){
        visi[i]=1;
        for(auto it:adj[i]){
            if(!visi[it]){
                dfs(it,visi,adj,n);
            }
        }

    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>visi(n,0);
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(!visi[i]){
                dfs(i,visi,adj,n);
            }
            if(!visi[source] && visi[destination]) return false;
            else if(visi[source] && !visi[destination]) return false;
        }
        return true;
    }
};