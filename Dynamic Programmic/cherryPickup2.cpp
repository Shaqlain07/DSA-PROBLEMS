class Solution {
private:
    int dfs(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp) {
        int m=grid.size();
        int n=grid[0].size();
        //base case
        if(j1<0 || j1>=n || j2<0 || j2>=n) {
            return -1e9;
        }
        if(i==m-1) {
            if(j1==j2) return grid[i][j1];
            return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

        //explore all the test case
        int mx=-1e8;
        for(int r1=-1;r1<=1;r1++) {
            for(int r2=-1;r2<=1;r2++) {
                int temp=0;
                if(j1==j2) temp=grid[i][j1];
                else temp=grid[i][j1]+grid[i][j2];
                temp+=dfs(i+1,j1+r1,j2+r2,grid,dp);
                mx=max(mx,temp);
            }
        }
        return dp[i][j1][j2]=mx;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //3d dp
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return dfs(0,0,n-1,grid,dp);
    }
};
