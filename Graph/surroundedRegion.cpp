class Solution {
private:
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>> &vis) {
        int m=board.size();
        int n=board[0].size();
        int deltaR[]={-1,0,1,0};
        int deltaC[]={0,1,0,-1};
        vis[i][j]=1;
        for(int k=0;k<4;k++) {
            int r=i+deltaR[k];
            int c=j+deltaC[k];

            //check if we can go then call the fn
            if(r>=0 && r<m && c>=0 && c<n && !vis[r][c] && board[r][c]=='O') {
                
                dfs(r,c,board,vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        //Iterate on row
        for(int j=0;j<n;j++) {
            //first row
            if(!vis[0][j] && board[0][j]=='O') {
                //vis[0][j]=1;
                dfs(0,j,board,vis);
            }
            //last row
            if(!vis[m-1][j] && board[m-1][j]=='O') {
                //vis[m-1][j]=1;
                dfs(m-1,j,board,vis);
            }
        }
        //Iterate on col
        for(int i=0;i<m;i++) {
            //first col
            if(!vis[i][0] && board[i][0]=='O') {
                //vis[i][0]=1;
                dfs(i,0,board,vis);
            }
            //last col
            if(!vis[i][n-1] && board[i][n-1]=='O') {
                //vis[i][n-1]=1;
                dfs(i,n-1,board,vis);
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!vis[i][j] && board[i][j]=='O') {
                    board[i][j]='X';
                }
            }
        }
    }
};
