class Solution {
public:
    vector<vector<int>> directions{{1, 0},{0,1},{-1,0},{0,-1}};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        vector<vector<int>>result(rows,vector<int>(cols,INT_MAX));
        result[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto curr=pq.top();
            int wt=curr.first;
            int row=curr.second.first;
            int col=curr.second.second;
            pq.pop();
            if(row==rows-1 && col==cols-1) return wt;
            for(auto dir:directions){
                int nr=row+dir[0];
                int nc=col+dir[1];
                if(nr>=0 && nr<rows && nc>=0 && nc<cols ){
                    int diff=abs(heights[nr][nc]-heights[row][col]);
                    int maxEffort=max(wt,diff);
                    if(maxEffort<result[nr][nc]){
                        result[nr][nc]=maxEffort;
                        pq.push({maxEffort,{nr,nc}});
                    }
                    // if(result[nr][nc]<result[row][col]) result[nr][nc]=result[row][col];
                }
            }
        }
        return 0;
    }
};