class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (i == parent[i])
            return i;
        return parent[i] = find(parent[i], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            rank[x_parent]++;
            parent[y_parent] = x_parent;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        vector<int> parent(26);
        vector<int> rank(26, 0);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < equations.size(); i++) {
            if (equations[i][1] == '=') {
                Union(equations[i][0] - 'a', equations[i][3] - 'a', parent,
                      rank);
            } 
        }
        
        for(int i=0;i<n;i++){
            if(equations[i][1]=='!'){
                int x = find(equations[i][0] - 'a', parent);
                int y = find(equations[i][3] - 'a', parent);
                if (x == y)
                    return false;
            }
        }

        return true;
    }
};