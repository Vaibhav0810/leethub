class Solution {
public:
     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
         
         
         
        int oColor=image[sr][sc];
         
         // ye isilie bcoz agr oColor = newcolor h to kuch krne ki zroort ni h bs direct return krdo
         if(oColor==newColor)return image;
        int n=image.size();
        int m=image[0].size();
        dfs(sr,sc,image,oColor,newColor,n,m);
        
        return image;
    }
    
    void dfs(int row,int col,vector<vector<int>> &image,int oColor,int color,int n,int m){
        
        if(row<n && col<m && row>=0 && col>=0 && image[row][col]==oColor/*&&image[row][col]!=color ye case yha bhi lg skta*/){
            
            image[row][col]=color;
            
            // ye sare constraint islie bcoz sirf 4 direction mei travel krna h aur jb aisa krenge to ye sb bnega
            // like upr jaayenge to row-1 hoga and col same rhega aise hi sare alg alg h
            dfs(row-1,col,image,oColor,color,n,m);
            dfs(row,col-1,image,oColor,color,n,m);
            dfs(row,col+1,image,oColor,color,n,m);
            dfs(row+1,col,image,oColor,color,n,m);
        }
        else return;
    }
};