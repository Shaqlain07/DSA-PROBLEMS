//using bfs
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i==0 && j==0) continue;
                int sum1,sum2=INT_MAX;
                if(i>0) sum1=dp[i-1][j];
                if(j>0) sum2=dp[i][j-1];
                dp[i][j]=grid[i][j]+min(sum1,sum2);
            }
        }
        return dp[m-1][n-1];
    }
};
