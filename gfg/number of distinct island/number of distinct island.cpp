
// visi vector ke sath 2 test case pass ni ho rhe the last ke dikkt de rhe the isilie bina visi ke kra h to ho gya

int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        if(n==0) return 0;
        int m=grid[0].size();
        if(m==0) return 0;
        //vector<vector<int>>visi(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>>st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    vector<pair<int,int>>v;
                    dfs(i,j,grid,v,i,j);
                    st.insert(v);
                }
            }
        }
        return st.size();
        
        
    }
    
    void dfs(int row,int col,vector<vector<int>>&grid,vector<pair<int,int>>&v,int row0,int col0){
        grid[row][col]=0;
        v.push_back({row-row0,col-col0});
        int n=grid.size();
        int m=grid[0].size();
        
        int delrow[]={-1,0,0,1};
        int delcol[]={0,-1,1,0};
        
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,v,row0,col0);
            }
            
        }
        
    }
