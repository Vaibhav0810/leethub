
 public:
    // Function to detect cycle in a directed graph.
    
    // LOGIC- hmne topological sort mei kahn's algo dekha tha vo sirf directed acylic graph mei lgta h
    // so idhr hm dekhenge agr ye algo lgg paa rha h mtlb cycle ni h else cycle h
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int> vis(V,0);
        queue<int>q;
        vector<int>indeg(V,0);
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        
        for(int i=0;i<indeg.size();i++){
            if(indeg[i]==0) q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        // so isme dekhenge agr count ne apna kaam pura kr dia h hrr var pr jaa chuka h
        // mtlb isme topo sort lgg rha h aur ye cyclic ni h
        // else cyclic h
        if(count==V) return false;
        else return true;
        
    }
