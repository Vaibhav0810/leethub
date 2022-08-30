
#include <bits/stdc++.h>

using namespace std;

    bool help(int node,vector<int>& color,vector<int>adj[]){
        queue<int>q; // for storing bfs
        color[node]=1;
        q.push(node);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node]){
                if(color[it]==-1){
                    color[it]=1-color[node];
                    q.push(it);
                    
                }
                else if(color[it]==color[node]) return false; // mtlb agr adj nodes ka color same h to mtlb glt h
            }
            
        }
        return true;
    }
    
    
    bool isbap(int V,vector<int>adj[]){
        vector<int>color(V,-1); // ik color vector bnaya h jisse -1 se initilize kr dia h sara
        
        for(int i=0;i<V;i++){ // bcoz agr bht sare components ho to unn sbko cover kr initilize
        
            if(color[i]==-1){ // iska mtlb h ye abhi tk visit ni hua h
                if(!help(i,color,adj)) return false;// mtlb agr vo function false return kre to tum bhi false return krdo            
            }
            
        }
        return true;
    }
    
    
    


int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    //Solution s;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isbap(n,adj)){
        cout<<"ues";
    }
    else{
        cout<<"NO";
    }
    return 0;
}
