class Solution{
  
   public:
    // Function to detect cycle in an undirected graph.
    
    // TIME-O(N+E) SPACE-O(N+E)+O(N)+O(N)
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> visi(V,0);
        
        for(int i=0;i<V;i++){
            if(!visi[i]){
                if(help(i,-1,visi,adj)) return true; // iss line ka mtlb h agr ye true return kr rha to tum bhi true return krdo
            }
        }
        return false;
    }
    
    bool help(int node,int parent,vector<int> & visi,vector<int> adj[]){
        visi[node]=1;
        
        for(auto it:adj[node]){
            if(!visi[it]){
                if(help(it,node,visi,adj)) return true;//iss line ka mtlb h agr ye true return kr rha to tum bhi true return krdo aage traverse krne ki jroor hi ni h bs ik true mil gya khtm   
               }
               else if(it!=parent) return true;
            
        }
        return false;
    }
    
  
};
