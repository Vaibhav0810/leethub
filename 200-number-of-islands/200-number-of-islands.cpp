//     class Solution
//     {
//         public:
//             int numIslands(vector<vector < char>> &grid)
//             {

//                 int n = grid.size();
//                 int m = grid[0].size();
//                 int count = 0;
//                 vector<vector < int>> visi(n, vector<int> (m, 0));

//                 for (int i = 0; i < n; i++)
//                 {
//                     for (int j = 0; j < m; j++)
//                     {
//                         if (!visi[i][j] && grid[i][j] == '1')
//                         {
//                             count++;
//                             bfs(i, j, visi, grid);
//                         }
//                     }
//                 }
//                 return count;
//             }

//         private:
//             void bfs(int row, int col, vector<vector < int>> &visi, vector< vector< char>> grid)
//             {
//                 visi[row][col] = 1;
//                 queue<pair<int, int>> q;
//                 q.push({ row,
//                     col });
//                 int n = grid.size();
//                 int m = grid[0].size();

//                 while (!q.empty())
//                 {
//                     int row = q.front().first;
//                     int col = q.front().second;
//                     q.pop();
//                    	// ye 3 cases isilie bcoz iss Q mei diagonal check ni krna aur agr diagonal bhi check                        krna ho to
//                    	// del row vala jaise del col ka loop andr uske aur baaki code ik brr bs

//                    	//traverse neighbours and mark them land
//                    	// ye sb iislie bcoz hm ksisi bhi direction mei check kr skte h diagonaly erticall                            horizontally
//                    	// so upr vala element hoga row -1 neeche  vala row +1 and same for column aise
//                     for (int delrow = -1; delrow <= 1; delrow++)
//                     {
//                         if (delrow == -1)
//                         {

//                             int delcol = 0;
//                             int nrow = row + delrow;
//                             int ncol = col + delcol;
//                            	// now cehck krna h vaalid h ya ni bcoz agr sbse upr h to hm usse ni bolskte ki tu aur upr ka check kr
//                             if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !visi[nrow][ncol])
//                             {
//                                 visi[nrow][ncol] = 1;
//                                 q.push({ nrow,
//                                     ncol });
//                             }
//                         }
//                         else if (delrow == 1)
//                         {
//                             int delcol = 0;
//                             int nrow = row + delrow;
//                             int ncol = col + delcol;
//                            	// now cehck krna h vaalid h ya ni bcoz agr sbse upr h to hm usse ni bolskte ki tu aur upr ka check kr
//                             if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !visi[nrow][ncol])
//                             {
//                                 visi[nrow][ncol] = 1;
//                                 q.push({ nrow,
//                                     ncol });
//                             }
//                         }
//                         else if (delrow == 0)
//                         {
//                             for (int delcol = -1; delcol <= 1; delcol = delcol + 2)
//                             {

//                                 int nrow = row + delrow;
//                                 int ncol = col + delcol;
//                                	// now cehck krna h vaalid h ya ni bcoz agr sbse upr h to hm usse ni bolskte ki tu aur upr ka check kr
//                                 if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !visi[nrow][ncol])
//                                 {
//                                     visi[nrow][ncol] = 1;
//                                     q.push({ nrow,
//                                         ncol });
//                                 }
//                             }
//                         }
//                     }
//                 }
//             }
//     };

// ye upr ke aise 3 cases ki jgh array le skte h ye upr ka krne se acha ni lgta code so
int delrow[]={-1,0,1,0}
int delcol[]={0,1,0,-1}
// for(int i=0;i<4;i++){
//int nrow=row+delrow
// int ncol=col+delcol


// dfs version
// isme visi matrix ni lia bcoz uski vjh se tle aa rha h

class Solution
{
    public:

        int numIslands(vector<vector < char>> &grid)
        {
            int n = grid.size();
            int m = grid[0].size();
            
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == '1')
                    {
                        count++;
                        dfs(i, j, grid);
                    }
                }
            }
            return count;
        }

    void dfs(int row, int col,vector< vector< char>> &grid)
    {
        
        int n=grid.size();
        int m=grid[0].size();
        if(row>=0 && col>=0 && row<n && col<m && grid[row][col]=='1'){
            grid[row][col]='0';
            dfs(row-1,col,grid);
            dfs(row,col-1,grid);
            dfs(row,col+1,grid);
            dfs(row+1,col,grid);
        }
        else return;
        
    }
};
