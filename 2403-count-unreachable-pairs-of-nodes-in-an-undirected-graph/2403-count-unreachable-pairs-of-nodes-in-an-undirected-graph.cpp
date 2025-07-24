class Solution {
public:
    int find(int i,vector<int>&parent){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i],parent);
    }

    void Union(int x, int y, vector<int>&parent, vector<int>&rank){
        int x_parent=find(x,parent);
        int y_parent=find(y,parent);

        if(x_parent==y_parent) return;

        if(rank[x_parent]>rank[y_parent]) parent[y_parent]=x_parent;
        else if(rank[x_parent]<rank[y_parent]) parent[x_parent]=y_parent;
        else {
            rank[x_parent]++;
            parent[y_parent]=x_parent;
        }

    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        long long ans=0;
        for(int i=0;i<edges.size();i++){
            if(find(edges[i][0],parent)!=find(edges[i][1],parent)){
                Union(edges[i][0],edges[i][1],parent,rank);
            }
        }
        // for(int i=0;i<n;i++) cout<<parent[i]<<" ";
        vector<int>count(n,0);
        for(int i=0;i<n;i++){
            int root = find(i, parent);
            count[root]++;

        }
        int x=n;
        for(int i=0;i<n;i++){
            if(count[i]>0){
                x-=count[i];
                ans+=(long long)count[i]*x;
            }
        }
        return ans;
    }
};