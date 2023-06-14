class Solution {
public:
    void island(vector<vector<char>> &grid,int i,int j) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return;
        if(grid[i][j]=='0') return;
        grid[i][j]='0';
        //call on left
        island(grid,i,j+1);
        //call on right
        island(grid,i,j-1);
        //call top
        island(grid,i-1,j);
        //call bottom
        island(grid,i+1,j);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='1') {
                    island(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
