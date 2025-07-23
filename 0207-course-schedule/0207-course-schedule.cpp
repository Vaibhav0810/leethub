class Solution {
public:

    //check cycle
    bool dfs(int i,vector<vector<int>>&adj,vector<int>&visi,vector<int>&inRec){
        visi[i]=1;
        inRec[i]=1;
        for(auto it:adj[i]){
            if(!visi[it] && dfs(it,adj,visi,inRec)){
                return true;
            }
            else if(inRec[it]) return true;
        }
        inRec[i]=0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>visi(numCourses,0);
        // bool check =false;
        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<int> inRec(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!visi[i] && dfs(i,adj,visi,inRec)){
                return false;
            }
        }
        return true;
    }
};