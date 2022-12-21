//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        
        vector<pair<int,int>>adj[n];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        vector<int>dist(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        dist[0]=0;
        int count=0;
        // dist from
        pq.push({0,0});
        while(!pq.empty()){
            auto itr=pq.top();
            int wt=itr.first;
            int src=itr.second;
            
            pq.pop();
            if(src==n-1) continue;
            for(auto it:adj[src]){
                int length=it.second;
                int node=it.first;
                if(node==n-1 && dist[node]==length+wt){
                    count++;
                    
                    
                }
                else if(node==n-1 && dist[node]>length+wt) count=1;
                
                if(dist[node]>=length+wt){
                    dist[node]=length+wt;
                    pq.push({dist[node],node});
                }
                
            }
            
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends