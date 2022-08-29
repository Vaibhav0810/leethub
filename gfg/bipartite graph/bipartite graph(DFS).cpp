TIME - O(V+E) SPACE-O(V) 
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int>colored(V,-1);
	    
	    for(int i=0;i<V;i++){
	        if(colored[i]==-1){
	            if(!help(i,colored,adj)) return false;
	        }
	    }
	    return true;
	}
	
	bool help(int node,vector<int> colored,vector<int> adj[]){
	    
	    if(colored[node]==-1) colored[node]=1; // agr phle kbhi visit ni hua h to 
	    
	    for(auto it:adj[node]){
	        if(colored[it]==-1){
	            colored[it]=1-colored[node];
	            if(!help(it,colored,adj)) return false; // bcoz agr ik false aajayega to bs tuum false return krte rhe aage jaane ki zroort hini h
	        }
	        else if(colored[node]==colored[it]) return false;
	    }
	    return true;
	}
