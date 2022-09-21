class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int delrow[]={-1,0,0,1};
        int delcol[]={0,-1,1,0};
        
        vector<vector<int>>visi(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++){
            
            if(!visi[0][j] && grid[0][j]==1){
                dfs(0,j,visi,grid,delrow,delcol);
            }
            
            if(!visi[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,visi,grid,delrow,delcol);
            }
            
        }
        
        for(int i=0;i<n;i++){
            if(!visi[i][0] && grid[i][0]==1){
                dfs(i,0,visi,grid,delrow,delcol);
            }
            
            if(!visi[i][m-1]&& grid[i][m-1]==1){
                dfs(i,m-1,visi,grid,delrow,delcol);
            }
            
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visi[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
    
    void dfs(int row,int col, vector<vector<int>>&visi, vector<vector<int>>&grid,int delrow[],int delcol[]){
        int n=grid.size();
        int m=grid[0].size();
        visi[row][col]=1;
        grid[row][col]=0;
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1 && !visi[nrow][ncol]){
                dfs(nrow,ncol,visi,grid,delrow,delcol);
            }
            
        }
        
        
    }
    
};