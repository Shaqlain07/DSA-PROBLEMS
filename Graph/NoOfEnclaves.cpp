//problem
  //   In a 2d matrix, find no of cells (1) which are neither at the boundary nor connected to 	boundary,
class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>> &vis) {

        int m=grid.size();
        int n=grid[0].size();
        int deltaR[]={-1,0,1,0};
        int deltaC[]={0,1,0,-1};

        for(int i=0;i<4;i++) {
            int newR=r+deltaR[i];
            int newC=c+deltaC[i];

            if(newR>=0 && newR<m && newC>=0 && newC<n && !vis[newR][newC] && grid[newR][newC]==1) {
                vis[newR][newC]=1;
                dfs(newR,newC,grid,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        // Iterate on boundary
        //top and bottom row
        for(int j=0;j<n;j++) {
            //first row
            if(grid[0][j]==1) {
                vis[0][j]=1;
                dfs(0,j,grid,vis);
            }
            //last row
            if(grid[m-1][j]==1) {
                vis[m-1][j]=1;
                dfs(m-1,j,grid,vis);
            }
        }
        //first and last col
        for(int i=0;i<m;i++) {
            //first col
            if(grid[i][0]==1) {
                vis[i][0]=1;
                dfs(i,0,grid,vis);
            }
            //last col
            if(grid[i][n-1]==1) {
                vis[i][n-1]=1;
                dfs(i,n-1,grid,vis);
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!vis[i][j] && grid[i][j]==1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
