// same as check cycle in directed graph
// in this anyone who is a part of cycle and wnyone who leads to a cycle wont be a safe node

// Time- o(v+e)
// space- O(V)
class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        vector<int>ans;
        vector<int>path(V,0);
        vector<int>visi(V,0);
        int check[V]={0};
        for(int i=0;i<V;i++){
            if(!visi[i]){
                dfs(i,visi,path,adj,check);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
    }
    
    bool dfs(int node,vector<int>&visi,vector<int>&path,vector<int>adj[],int check[]){
        visi[node]=1;
        path[node]=1;
        check[node]=0;
        for(auto it:adj[node]){
            if(!visi[it]){
                if(dfs(it,visi,path,adj,check)==true){
                check[node]=0;
                return true;
                }
            }
            else if(path[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        path[node]=0;
        return false;
    }
    
};
