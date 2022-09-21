class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visi(n,vector<int>(m,0));
        int delrow[]={-1,0,0,1};
        int delcol[]={0,1,-1,0};
        
        for(int j=0;j<m;j++){
            
            if(!visi[0][j] && board[0][j]=='O')
            dfs(0,j,visi,board,delrow,delcol);
            
            if(!visi[n-1][j] && board[n-1][j]=='O')
            dfs(n-1,j,visi,board,delrow,delcol);
            
        }
        
        for(int i=0;i<n;i++){
            
            if(!visi[i][0] && board[i][0]=='O')
            dfs(i,0,visi,board,delrow,delcol);
            
            if(!visi[i][m-1] && board[i][m-1]=='O')
            dfs(i,m-1,visi,board,delrow,delcol);
            
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !visi[i][j]){
                    visi[i][j]=1;
                    board[i][j]='X';
                }
            }
        }
        
        return;
        
    }
    
    void dfs(int row,int col,vector<vector<int>>&visi,vector<vector<char>>&board,int delrow[],int delcol[]){
        int n=board.size();
        int m=board[0].size();
        visi[row][col]=1;
        
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && board[nrow][ncol]=='O' && !visi[nrow][ncol]){
                dfs(nrow,ncol,visi,board,delrow,delcol);
            }
            
        }
        
    }
    
};