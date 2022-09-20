
// isme phle hm dekhenge kha kha 1 h jha jha one ho usko queue mei push kr lenge firr uss se next zeroes ka dist dhundenge aur unhe dist vector mei push krte
// rhenge aur end mei dist vect return


   // time comp - n*m for loop then n*m while !q.empty(worst case jb sare hi one ho to sare hi push hojayenge na queuue mei) * 4 del row vale loop ke lie
   // approx=n*m
   //  space - O(N*M)
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    
	    
	    queue<pair<pair<int,int>,int>>q;
	    
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>visi(n,vector<int>(m,0));
	    vector<vector<int>>dist(n,vector<int>(m,0));
	    int delrow[]={-1,0,0,1};
	    int delcol[]={0,1,-1,0};
	   
	   
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[0].size();j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                visi[i][j]=1;
	            }
	            else {
	               // visi[i][j]=0;
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        int row=q.front().first.first;
	        int col=q.front().first.second;
	        int steps=q.front().second;
	        q.pop();
	        dist[row][col]=steps;
	        
	        for(int i=0;i<4;i++){
	            int nrow=delrow[i]+row;
	            int ncol=delcol[i]+col;
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visi[nrow][ncol]==0){
	                visi[nrow][ncol]=1;
	                q.push({{nrow,ncol},steps+1});
	            }
	        }
	        
	    }
	    return dist;
	}
