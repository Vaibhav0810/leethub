class Solution {
public:

    bool bfs(int i,vector<vector<int>>&adj,vector<int>&color){
        color[i]=1;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto it:adj[curr]){
                if(color[it]==-1){
                    color[it]=!color[curr];
                    q.push(it);
                }
                else if(color[it]==color[curr]) return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n, -1);
        vector<vector<int>>adj(n);
        for(auto it:dislikes){
            int u=it[0];
            int v=it[1];
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        for(int i=0;i<n;i++){
            if(color[i]==-1 && !bfs(i,adj,color)) return false;;
        }

        return true;
    }
};