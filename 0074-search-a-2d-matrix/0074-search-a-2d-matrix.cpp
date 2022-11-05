class Solution {
public:
    // aise ni hoga
//     bool search(vector<vector<int>>&matrix,int target,int s1,int s2,int e1,int e2){
        
//         if(target>matrix[e1][e2] && e1+1<matrix.size()){
//             return search(matrix,target,s1+1,s2,e1+1,e2);
//         }
//         else if(target==matrix[e1][e2]) return true;
//         else{
        
//         int mid1=(e1-s1)/2;
//         int mid2=(e2-s2)/2;
        
//         if(target<matrix[mid1][mid2]){
//             return search(matrix,target,s1,s2,mid1,mid2);
//         }
//         else if(target>matrix[mid1][mid2]){
//             return search(matrix,target,mid1,mid2,e1,e2);   
//         }
//         else if(target==matrix[mid1][mid2]){
//             return true;
//         }
//         }
//         return false;
        
//     }
    
    // Brute
    // see this as a bst
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        
        int row=0,col=cols-1;
        
        while(row<rows && col>-1){
            
            if(target==matrix[row][col]) return true;
            else if(matrix[row][col]>target) col--;
            else row++;
        }
        return false;
    }
};