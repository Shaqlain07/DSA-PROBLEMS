class Solution {
public:
    bool check(vector<string> &board,int row,int col) {
        //column check
        for(int i=0;i<row;i++) {
            if(board[i][col]=='Q') {
                return false;
            }
        }
        //upper left diagonal
        int r=row;
        int c=col;
        while(r>=0 && c>=0) {
            if(board[r][c]=='Q') {
                return false;
            }
            r--;
            c--;
        }
        //upper right diagonal
         r=row;
         c=col;
        while(r>=0 && c<size(board)) {
            if(board[r][c]=='Q') {
                return false;
            }
            r--;
            c++;
        }
        return true;
    }
    void NQueen(vector<string> &board,int &ans,int row) {
        if(row==size(board)) {
            ans++;
            return;
        }
        for(int col=0;col<size(board);col++) {
            if(check(board,row,col)) {
                board[row][col]='Q';
                
                NQueen(board,ans,row+1);
                
                board[row][col]='-'; //backtracking
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'-'));
        int ans=0;
        NQueen(board,ans,0);
        return ans;
        
    }
};
