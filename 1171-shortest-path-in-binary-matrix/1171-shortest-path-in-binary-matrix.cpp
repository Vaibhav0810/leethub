class Solution {
public:
    vector<vector<int>> directions{{1, 1},  {1, 0},  {0, 1},   {-1, 0},
                                   {0, -1}, {1, -1}, {-1, -1}, {-1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int V = grid.size();

        if(grid[0][0]==1 || grid[V-1][V-1]==1) return -1;
        if(V-1==0) return 1;
        vector<vector<int>>result(V,vector<int>(V,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        grid[0][0]=1;
        result[0][0]=1;
        int count=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int dist=curr.first;
            int row=curr.second.first;
            int col=curr.second.second;
            // if(row==V-1 && col==V-1) return result[row][col]+1;
            for(auto dir:directions){
                int nr=row+dir[0];
                int nc=col+dir[1];
                int ans=1;
                if(nr>=0 && nr<V && nc>=0 && nc<V && grid[nr][nc]==0 && dist+ans<result[nr][nc]){
                    result[nr][nc]=dist+1;
                    // grid[nr][nc]=1;
                    pq.push({result[nr][nc],{nr,nc}});
                }
            }
        }
        if(result[V-1][V-1]==INT_MAX)
        return -1;
        else return result[V-1][V-1]+1;
    }
};