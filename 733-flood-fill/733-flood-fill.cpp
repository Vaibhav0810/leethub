class Solution {
public:
     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
         
         
         
        int oColor=image[sr][sc];
         if(oColor==newColor)return image;
        int n=image.size();
        int m=image[0].size();
        dfs(sr,sc,image,oColor,newColor,n,m);
        
        return image;
    }
    
    void dfs(int row,int col,vector<vector<int>> &image,int oColor,int color,int n,int m){
        
        if(row<n && col<m && row>=0 && col>=0 && image[row][col]==oColor){
            image[row][col]=color;
            dfs(row-1,col,image,oColor,color,n,m);
            dfs(row,col-1,image,oColor,color,n,m);
            dfs(row,col+1,image,oColor,color,n,m);
            dfs(row+1,col,image,oColor,color,n,m);
        }
        else return;
    }
};