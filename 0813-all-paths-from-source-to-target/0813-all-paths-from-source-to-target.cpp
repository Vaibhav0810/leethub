class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int i, vector<int>& visi, vector<vector<int>>& graph,
             vector<int> temp, int n) {
        // visi[i]=1;
        temp.push_back(i);
        if (i == n - 1)
            ans.push_back(temp);
        for (auto it : graph[i]) {
            // temp.push_back(it);
            dfs(it, visi, graph, temp, n);
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visi(n, 0);
        vector<int> temp;
        // temp.push_back(0);
        dfs(0, visi, graph, temp, n);
        return ans;
    }
};