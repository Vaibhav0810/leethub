//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    // unit weights
    // private:
    // int dijkstra(vector<vector<int>>&grid,
    //     pair<int,int>source,pair<int,int>destination){
        
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     vector<int>path;
    //     vector<vector<pair<int,int>>>parent[n+1][m+1];
        
    //     // for(int i=1;i<=n;i++){
    //     //     for(int j=1;j<=m;j++){
    //     //         parent[i][j]={{i,j}};
    //     //     }
    //     // }
        
    //     int delrow[]={-1,0,0,1};
    //     int delcol[]={0,1,-1,0};
        
        
    //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    //     int one=source.first;
    //     int two=source.second;
    //     pq.push({one,two});
        
    //     while(!pq.empty()){
    //         int row=pq.top().first;
    //         int col=pq.top().second;
    //         pq.pop();
    //         for(int i=0;i<4;i++){
    //             int nrow=row+delrow[i];
    //             int ncol=col+delcol[i];
    //             if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1){
    //                 pq.push({nrow,ncol});
    //                 parent[nrow][ncol]={nrow,ncol};
    //                 if([nrow][ncol]==destination) break;
    //             }
    //         }
    //     }
        
    // }
    public:
    int bfs(vector<vector<int>>grid,pair<int,int>source,pair<int,int>destination){
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,(vector<int>(m,INT_MAX)));
        int one=source.first;
        int two=source.second;
        dist[one][two]=0;
        
        q.push({0,{source}});
        
        int delrow[]={-1,0,0,1};
        int delcol[]={0,1,-1,0};
        
        while(!q.empty()){
            int weight=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1 && weight+1<dist[nrow][ncol]){
                    q.push({weight+1,{nrow,ncol}});
                    
                        dist[nrow][ncol]=weight+1;
                    
                }
            }
        }
        one=destination.first;
        two=destination.second;
        if(dist[one][two]==INT_MAX) return -1; 
        return dist[one][two];
    }
    
  
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        return bfs(grid,source,destination);
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends