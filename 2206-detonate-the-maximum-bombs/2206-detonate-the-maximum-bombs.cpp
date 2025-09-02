class Solution {
public:


    void dfs(int i,vector<vector<int>>&adj,vector<int>&visi,int &count){
        visi[i]=1;
        count++;
        for(auto it:adj[i]){
            if(!visi[it]){
                // count++;
                dfs(it,adj,visi,count);
            }
        }
    }

    bool inZone(vector<vector<int>>&bombs,int i,int j){
        long long radius=bombs[i][2];
        radius*=radius;
        long long pt1=abs(bombs[j][0]-bombs[i][0]);
        long long pt2=abs(bombs[j][1]-bombs[i][1]);
        if(pt1*pt1 + pt2*pt2<=radius){
            return true;
        }
        return false;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        // int ans=0;
        int count=0;
        int n=bombs.size();
        vector<int>visi(n,0);

        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(inZone(bombs,i,j)){
                    adj[i].push_back(j);
                }
            }
        }
        // int size=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int count=0;
            vector<int>visi(n,0);
            dfs(i,adj,visi,count);
            ans=max(ans,count);
        }
        return ans;
        
    }
};