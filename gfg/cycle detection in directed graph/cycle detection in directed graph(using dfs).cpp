
Q WHY cant we use undirected graph formula here ?
A bcoz just suppose graph is like this 
  
  3->4->5
  3->6->5
  
  agr aise mei hm undirected ka lgayenge to vo cycle bol dega isse but it isnt a cycle thats why we do it like this
  
    // so isme hmm do array bnaynege ik vis jo apna regular hrr brr kaam krta h
    // 2nd dfs array isse bhi hrr visited ki trh 1 mark krte chlenge but jb hm recursion mei vps aa rhe honge to hm jitna vps aayenge isse vps utna 0 krdenge bcoz 
    // directed grap h to cycle linked si honi chahie na arrows se and when linked milegi and hm dekhenge uska dfs phle se visited h to true return kr denge
    
    
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int>vis(V,0);
        vector<int>dfs(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(help(i,vis,dfs,adj)) return true;
            }
        }
        return false;
    }
    
    bool help(int node,vector<int>vis,vector<int>dfs,vector<int>adj[]){
        vis[node]=1;
        dfs[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(help(it,vis,dfs,adj)) return true;
            }
            else if(dfs[it]) return true;
        }
        dfs[node]=0;
        return false;
    }
    
