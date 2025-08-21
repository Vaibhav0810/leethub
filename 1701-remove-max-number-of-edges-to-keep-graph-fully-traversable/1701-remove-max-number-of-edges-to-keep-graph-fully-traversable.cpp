class DSU{
    public:
    vector<int>parent;
    vector<int>rank;
    int components;

    DSU(int n){
        components=n;
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        rank.resize(n+1);

    }

    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent==y_parent) return;

        if(rank[x_parent]>rank[y_parent]) parent[y_parent]=x_parent;
        else if(rank[x_parent]<rank[y_parent]) parent[x_parent]=y_parent;
        else{
            rank[x_parent]++;
            parent[y_parent]=x_parent;
        }
        components--;
    }

    bool isSingleComponent(){
        return components==1;
    }
};

class Solution {
public:
    

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // int count1=0,count2=0;
        DSU Alice(n);
        DSU Bob(n);

        auto lambda = [](vector<int>&v1, vector<int>&v2){
            return v1[0]>v2[0];
        };

        sort(begin(edges),end(edges),lambda);
        int edgeCount=0;

        for(auto &vec:edges){
            bool toAddEdge=false;
            int type=vec[0];
            int u=vec[1];
            int v=vec[2];

            if(type==3){
                if(Alice.find(u)!=Alice.find(v)){
                    Alice.Union(u,v);
                    toAddEdge=true;
                }
                if(Bob.find(u)!=Bob.find(v)){
                    Bob.Union(u,v);
                    toAddEdge=true;
                }
                if(toAddEdge) edgeCount++;
                toAddEdge=0;
            }
            else if(type==2){
                if(Bob.find(u)!=Bob.find(v)){
                    Bob.Union(u,v);
                    edgeCount++;
                }
            }
            else{
                if(Alice.find(u)!=Alice.find(v)){
                    Alice.Union(u,v);
                    edgeCount++;
                }
            }
        }

        if(Alice.isSingleComponent() && Bob.isSingleComponent()) return edges.size()-edgeCount;

        return -1;

    }
};