class Solution {
public:
    bool checkRow(int row, int col, vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            if(i == row) continue;
            if(board[i][col] == board[row][col]) return false;
        }
        return true;
    }
    bool checkCol(int row, int col, vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            if(i == col) continue;
            if(board[row][i] == board[row][col]) return false;
        }
        return true;
    }
    bool checkGrid(int row, int col, vector<vector<char>>& board){
        int startR = (row / 3) * 3, startC = (col / 3) * 3;

        for(int i = 0; i < 9; i++){
            int currR = startR + i/3, currC = startC + i%3;
            if(currR == row && currC == col) continue;
            if(board[currR][currC] == board[row][col]) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    bool rowClear = checkRow(i, j, board);
                    bool colClear = checkCol(i, j, board);
                    bool gridClear = checkGrid(i, j, board);

                    if(!rowClear || !colClear || !gridClear) return false;
                }
            }
        }

        return true;
    }
};