class Solution {
public:

    
     bool isValidSudoku(vector<vector<char>>& board) {
//         int n=board.size();
//         int m=board[0].size();
//         set<char>st;
        
//         for(int i=0;i<n;i++){

//             for(int j=0;j<m-1;j++){
//                 if(st.find(board[i][j])!=st.end() && board[i][j]!='.'){
//                     return false;
//                 }
//                 else st.insert(board[i][j]);
//             }
//             st.clear();
            
//         }
//         st.clear();
        
        
//         for(int j=0;j<m;j++){
//             for(int i=0;i<n-1;i++){
//                 if(st.find(board[i][j])!=st.end() && board[i][j]!='.'){
//                     return false;
//                 }
//                 else st.insert(board[i][j]);
//             }
//             st.clear();
//         }
//         st.clear();
        
//         int x=0;
//         int xx=0;
//         while(x<n){
//             for(int i=x;i<x+3;i++){
                
//                 while(xx<m && i<x+3){
                    
//                 for(int j=xx;j<xx+3;j++){
//                     if(st.find(board[i][j])!=st.end() && board[i][j]!='.'){
//                         return false;
//                     }
//                     else st.insert(board[i][j]);
//                 }
//                     i++;
//                     if(i==x+3){
//                         xx+=3;
//                         i=0;
//                         st.clear();
//                     }
                    
//                 }
//                 st.clear();
//                 break;
//             }

//             x+=3;
//             xx=0;
//             st.clear();
//         }
        
//        return true;
    
        
        vector<set<int>> rows(9), cols(9), blocks(9);
     
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                if(board[i][j]=='.') continue;
                
                int curr=board[i][j]-'0';
                if(rows[i].count(curr) || cols[j].count(curr) || blocks[(i/3)*3+j/3].count(curr)) return false;
                
                rows[i].insert(curr);
                cols[j].insert(curr);
                blocks[(i/3)*3+j/3].insert(curr);
                
            }
        }
        return true;
    }
};