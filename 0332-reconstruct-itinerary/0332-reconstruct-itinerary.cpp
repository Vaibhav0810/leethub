class Solution {
public:
    void dfs(unordered_map<string, multiset<string>> &adj, vector<string>& ans,
             string start) {

        while(!adj[start].empty()) {
            string next = *adj[start].begin();
            adj[start].erase(adj[start].begin());
            dfs(adj, ans, next);
        }
        ans.push_back(start);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // int n=tickets.size();
        unordered_map<string, multiset<string>> adj;
        for (auto& it : tickets) {
            adj[it[0]].insert(it[1]);
        }
        vector<string> ans;
        dfs(adj, ans, "JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};