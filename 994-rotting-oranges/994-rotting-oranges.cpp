
class Solution {
public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int count=0;
//         int n=grid.size();
//         int m=grid[0].size();
//         for(int i=0;i<grid.size();i++){
//             for(int j=0;j<grid[0].size();j++){
//                 if(grid[i][j]==2){
//                     dfs(i,j,n,m,count,grid);
//                 }
//             }
//         }
        
//         return count;
//     }
    
//     void dfs(int row,int col,int n,int m,int &count,vector<vector<int>>& grid){
        
//         if(row>=0 && col>=0 && row<n && col < m && grid[row][col]!=0){
//             grid[row][col]=2;
//             count++;

//             dfs(row-1,col,n,m,count,grid);
//             dfs(row,col+1,n,m,count,grid);
//             dfs(row,col-1,n,m,count,grid);
//             dfs(row+1,col,n,m,count,grid);

//         }
//         else return;
//     }
    
    int orangesRotting(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        
        
        
        // {{r,c}time}
        queue<pair<pair<int,int>,int>>q;
        int vis [n][m];
        int cntFresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    //grid[row][col]=0;
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j] ==1)cntFresh++;
            }
        }
        
        int tm=0;
        int delrow[]={-1,0,0,1};
        int delcol[]={0,1,-1,0};
        int cnt=0;
        
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            
            tm=max(tm,time);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=delrow[i]+row;
                int ncol=delcol[i]+col;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 &&  grid[nrow][ncol]==1){
                    vis[nrow][ncol]=2;
                    q.push({{nrow,ncol},time+1});
                    cnt++;
                }
            }
        
        }
    
    if(cnt != cntFresh) return -1;
    
    return tm;
    }
    
};