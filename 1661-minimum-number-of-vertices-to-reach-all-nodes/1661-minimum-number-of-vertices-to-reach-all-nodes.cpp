class Solution {
public:
    // Idea : Here idea is track of all the vertices from which we start traversing,
    //  and if we found vertex which is already in result set and reached by other 
    // vertex then we will remove it from result set beacuse vertex and all the 
    // vertices that can reached from that vertex can also be reached from other vertex.
    void dfs(int i,vector<vector<int>>&adj,vector<bool>&visi,set<int>&st){
        visi[i]=1;
        for(auto it:adj[i]){
            if(!visi[it]){
                dfs(it,adj,visi,st);
            }
            else{
                if(st.find(it)!=st.end()){
                    st.erase(it);
                }
            }
        }
    }

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<bool>visi(n,0);
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        set<int>st;
        for(int i=0;i<n;i++){
            if(!visi[i]){
                // ans.push_back(i);
                st.insert(i);
                dfs(i,adj,visi,st);
            }
        }
        for(auto it:st) ans.push_back(it);
        return ans;
    }
};