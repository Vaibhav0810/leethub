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

    int makeConnected(int n, vector<vector<int>>& connections) {
        int totalWires = connections.size();
        if(totalWires<n-1) return -1;
        vector<int>parent(n);
        vector<int>rank(n,0);
        int leftNodes=0;
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(int i=0;i<totalWires;i++){
            Union(connections[i][0],connections[i][1],parent,rank);
        }

        for(int i=0;i<n;i++){
            if(parent[i]==i)
            leftNodes++;
        }
        return leftNodes-1;
    }
};