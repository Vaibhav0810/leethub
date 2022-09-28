class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& pre) {
        
        vector<int>adj[V];
        vector<int>ans;
        vector<int>indeg(V,0);
        
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
            indeg[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto it:adj[x]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        
        if(ans.size()==V) return ans;
        else{
            ans.clear();
            return ans;
        }
        
    }
};