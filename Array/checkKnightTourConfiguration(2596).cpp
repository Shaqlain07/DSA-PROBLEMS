class Solution {
public:
    
    bool solve(vector<vector<int>>& grid,int c,int r,int n,int& t) {
        
        if(r < 0 || r >=t || c< 0 || c >= t) return false;
        if(grid[r][c]!=n) return false;
        if(grid[r][c] == t*t-1 && n == t*t-1) return true;
        
        
        return solve(grid,c+1,r+2,n+1,t)||
        
        
             solve(grid,c+1,r-2,n+1,t)||
        
        
             solve(grid,c+2,r+1,n+1,t)||
        
        
             solve(grid,c+2,r-1,n+1,t)||
        
        
             solve(grid,c-1,r+2,n+1,t)||
        
        
             solve(grid,c-1,r-2,n+1,t)||


             solve(grid,c-2,r+1,n+1,t)||
        
        
             solve(grid,c-2,r-1,n+1,t);
        
        
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int t=grid.size();
        return solve( grid,0,0,0,t);
    }
};
