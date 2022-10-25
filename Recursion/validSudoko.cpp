class Solution {
public:
    bool isSafe(vector<vector<char>> &board,int row,int col) {
        for(int i=0;i<9;i++) {
            //row check
            if(i!=col && board[row][i]==board[row][col]) {
                return false;
            }
            //col check
            if(i!=row && board[i][col]==board[row][col]) {
                return false;
            }
        }
            //grid check
            int row_start=row-row%3;
            int col_start=col-col%3;
            for(int i=0;i<3;i++) {
                for(int j=0;j<3;j++) {
                    if((i+row_start)!=row && (j+col_start)!=col && board[i+row_start][j+col_start]==board[row][col]) {
                        return false;
                    }
                }
            }
        return true;
    }
    
    bool sudoko(vector<vector<char>> &board,int row,int col) {
        //base case
        if(row==8 && col==9) {
            return true;
        }
        if(col==9) { //last col+1
            col=0;
            row++;
        }
        if(board[row][col]=='.') {
            return sudoko(board,row,col+1);
        }
        //we got integer
        if(isSafe(board,row,col)) {
           return sudoko(board,row,col+1);
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return sudoko(board,0,0);
    }
};
