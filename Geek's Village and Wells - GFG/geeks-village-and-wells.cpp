//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        
        vector<vector<int>>res(n,vector<int>(m,0));
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j] == 'W'){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                    res[i][j] = 0;
                }
            }
        }
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        
        while(!q.empty())
        {
            auto it = q.front();
            int row = it.first.first;
            int col = it.first.second;
            int dis = it.second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
               
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and (c[nrow][ncol] == 'H' || c[nrow][ncol] == '.') and res[nrow][ncol]==0)
                {
                    vis[nrow][ncol] = 1;
                    res[nrow][ncol] = dis+2;
                    q.push({{nrow,ncol},2+dis});
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] and c[i][j] == 'H')
                    res[i][j] = -1;
                if(c[i][j] == '.')
                    res[i][j] = 0;
            }
        }
        return res;

        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends