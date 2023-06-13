class Solution {
public:
    void island(vector<vector<int>> &grid,int i,int j,int &ans) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return;
        if(grid[i][j]==0) return;
        ans++;
        grid[i][j]=0;
        island(grid,i,j+1,ans);
        island(grid,i,j-1,ans);
        island(grid,i-1,j,ans);
        island(grid,i+1,j,ans);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1) {
                    int ans=0;
                    island(grid,i,j,ans);
                    res=max(res,ans);
                }
            }
        }
        return res;
    }
};
