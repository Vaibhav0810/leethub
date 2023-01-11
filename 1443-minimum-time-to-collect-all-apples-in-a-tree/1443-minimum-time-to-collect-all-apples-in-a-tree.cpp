class Solution {
public:
    
    int dfs(int node,int parent,vector<vector<int>>&adj,vector<bool>&hasApple){
        int time=0,childtime=0;
        for(auto child:adj[node]){
            if(child==parent) continue;
            childtime=dfs(child,node,adj,hasApple);
            
            if(childtime||hasApple[child]) time+=childtime+2;
        }
            return time;
        
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<vector<int>> adj(n);
        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        return dfs(0,-1,adj,hasApple);
    }
};