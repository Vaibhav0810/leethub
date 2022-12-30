class Solution {
public:
    
    // isme jo vector h vo uss index ke children h like in eg1 0 1&2 se connected h aise
    
    void dfs(int i,vector<vector<int>>&graph,vector<int>&path,vector<vector<int>>&ans){
        path.push_back(i);
        
        if(i==size(graph)-1){ // same meaning as graph.size()
            ans.push_back(path);
        }
        else{
        for(auto it:graph[i]){
            dfs(it,graph,path,ans);
        }}
        path.pop_back();
        
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>path;
        dfs(0,graph,path,ans);
        return ans;
    }
};