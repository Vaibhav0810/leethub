class Solution {
public:
    // Gives TLE
    // Time Comp - > O(N^2)
    // int dfs(int i, int st, vector<bool>inRec, vector<int>& edges, int count)
    // {
    //     inRec[i] = 1;
    //     int it = edges[i];
    //     if (it == -1) return -1; // no outgoing edge
    //     if (inRec[it] && it == st) return count;
    //     else if (inRec[it] && it != st) return -1;
    //     int res = dfs(it, st, inRec, edges, count + 1);
    //     // inRec[i] = 0;
    //     return res;
    // }

    // int longestCycle(vector<int>& edges) {
    //     int n = edges.size();
    //     vector<bool> inRec(n, 0);
    //     // int count = 0;
    //     int ans = 0;
    //     for (int i = 0; i < n; i++) {
    //         int count = dfs(i, i, inRec, edges, 0);
    //         ans = max(ans, count);
    //         // fill(inRec.begin(), inRec.end(), 0);
    //     }
    //     return ans == 0 ? -1 : ans + 1;
    // }

     int result = -1;
    
    void dfs(int u, vector<int>& edges, vector<bool> &visited, vector<int>& dist, vector<bool> &inRecursion) {
        
        if(u != -1) {
            
            visited[u] = true;
            inRecursion[u] = true;
            
            int v = edges[u];
            
            if(v != -1 && !visited[v]) {
                
                dist[v] = dist[u] + 1;
                
                dfs(v, edges, visited, dist, inRecursion);

            } else if(v != -1 && inRecursion[v] == true) { //cycle
                
                result = max(result, dist[u] - dist[v] +1);
                
            }
        
            inRecursion[u] = false;
        }
        
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        
        
        vector<bool> visited(n, false);
        
        vector<int> dist(n, 1);
        vector<bool> inRecursion(n, false);
        
        for(int i = 0 ; i<n; i++) {
            
            if(!visited[i]) {
                dfs(i, edges, visited, dist, inRecursion);
            }
            
        }
        
        return result;
        
    }
};