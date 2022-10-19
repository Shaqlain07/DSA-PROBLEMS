class Solution {
public:
    //check fn for putting the integer
    bool check(vector<vector<char>> board,int row,int col,int k) {
        for(int i=0;i<9;i++) {
            //column 
            if(board[i][col]==k) {
                return false;
            }
            //row
            if(board[row][i]==k) {
                return false;
            }
        }
        //check box
        int srow=row-row%3;
        int scol=col-col%3;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[i+srow][j+scol]==k) {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board,int row,int col) {
        //base case
        if(row==8 && col==9) {
            return true;
        }
        //we got at end of row
        if(col==9) {
            row++;
            col=0;
        }
        //we got integer
        if(board[row][col]!='.') {
            return solve(board,row,col+1);
        }
        //it got '.' at that position
        for(char i='1';i<='9';i++) {
            if(check(board,row,col,i)) {//check that we can place the integer at that place
                board[row][col]=i;
                
                if(solve(board,row,col+1)) {//recursive function
                    return true;
                }
                
                board[row][col]='.';//backtracking
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
        return;
    }
};
