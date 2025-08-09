class Solution {
public:
    bool isSimilar(string s1,string s2){
        int count=0;

        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i]){}
            else count++;
        }

        if(count<=2) return true;
        return false;
    }
    void dfs(int i,vector<bool>&visi,vector<vector<int>>adj){
        visi[i]=true;
        for(auto it:adj[i]){
            if(!visi[it]) dfs(it,visi,adj);
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        int n= strs.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>visi(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visi[i]){
                count++;
                dfs(i,visi,adj);
            }
        }
        return count;
    }
};