class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        // create 2 vectors row, col which stores
        // no of ones in that particular row and col
        int m=grid.size();
        int n=grid[0].size();

        vector<int> row(m,0);
        vector<int> col(n,0);

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                row[i]+=grid[i][j];
                col[j]+=grid[i][j];
            }
        } 
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                grid[i][j]=row[i]+col[j]-(n-row[i])-(m-col[j]);
            }
        }
        return grid;
    }
};
