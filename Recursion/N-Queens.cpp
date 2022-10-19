class Solution {
public:
    vector<vector<string>> ans;
    bool check(vector<string> &board,int row,int col) {
        //check for upper column
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q') {
                return false;
            }
        }
        //check for upper left diagonal
        int r=row;
        int c=col;
        while(r >=0 && c >=0) {
            if(board[r][c]=='Q') {
                return false;
            }
            r--;
            c--;
        }
        //check for upper right column
         r=row;
         c=col;
        while(r >=0 && c<size(board) ) {
            if(board[r][c]=='Q') {
                return false;
            }
            r--;
            c++;
        }
        return true;
    }
    //it places the queen at its possible places
    void nqueen(vector<string>&board,int row) {
        if(row==size(board)) {//last row +1
            ans.push_back(board);
            return ;
        }
        for(int col=0;col<size(board);col++) {
            if(check(board,row,col)) {//it is safe to place the queen
                board[row][col]='Q';
                
                nqueen(board,row+1);//if this fn works for true then only
                                 //it will return true
                
                board[row][col]='.';//backtracking
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        nqueen(board,0);
        return ans;
    }
};
