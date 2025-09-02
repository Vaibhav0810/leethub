class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>>& adj,
             string& src, string& dest,double &final, double prod, unordered_set<string>&visi) {
        if (src==dest) {
            final=prod;
            return;
        }
        visi.insert(src);

        for (auto it : adj[src]) {
            if(visi.find(it.first)==visi.end()){
                // prod*=it.second;
                dfs(adj,it.first,dest,final,prod*it.second,visi);
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        // return {};
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> adj;
        vector<string> visi;

        for (int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double wt = values[i];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, 1.0 / wt});
        }

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            string src = queries[i][0];
            string dest = queries[i][1];
            double sum = -1;
            double prod=1;
            if (adj.find(src) != adj.end()) {
                unordered_set<string>visi;
                dfs(adj, src, dest,sum, prod,visi);
            }
            ans.push_back(sum);
        }

        return ans;
    }
};