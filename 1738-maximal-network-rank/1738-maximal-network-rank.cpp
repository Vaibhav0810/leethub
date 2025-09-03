class Solution {
public:

    // void dfs()

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
         vector<unordered_set<int>> adj(n); 
         vector<int>indeg(n,0);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];

            adj[u].insert(v);
            adj[v].insert(u);
            indeg[u]++;
            indeg[v]++;
        }
       
        int ans=0;
        // int maxi=*max_element(indeg.begin(),indeg.end());

        for(int i=0;i<n-1;i++){
            // if(indeg[i]==maxi){
                for(int j=i+1;j<n;j++){
                    int rank=indeg[i]+indeg[j];
                    if(adj[i].count(j)) rank--;
                    ans=max(ans,rank);
                }
            // }
        }
        return ans;
    }
};