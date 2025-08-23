class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minX=INT_MAX, minY=INT_MAX,maxX=INT_MIN,maxY=INT_MIN;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(minX>i) minX=i;
                    if(minY>j) minY=j;
                    if(maxX<i) maxX=i;
                    if(maxY<j) maxY=j;
                }
            }
        }
        cout<<minX <<minY <<maxX <<maxY;
        return (((maxX-minX)+1) * ((maxY-minY)+1));
    }
};