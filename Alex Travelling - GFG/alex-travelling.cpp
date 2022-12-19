//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        pq.push({0,k});
        
        while(!pq.empty()){
            int weight=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjweight=it.second;
                int adjnode=it.first;
                if(dist[adjnode]>weight+adjweight){
                    dist[adjnode]=weight+adjweight;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        // sort bhi kr skte h ni to aise bhi 
        // sort(dist.begin(),dist.end());
        int count=0;
        for(int i=1;i<dist.size();i++){
            if(dist[i]==1e9) return -1;
            else count=max(count,dist[i]);
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends