// Using BFS traversal
class Solution {    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1)); 
        //no of ways to reach (0,0) from (0,0)
        if(obstacleGrid[0][0]!=1) {
            dp[0][0]=1;
        }
        else {
            dp[0][0]=0;
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i==0 && j==0) continue;
                if(obstacleGrid[i][j]==1) {
                    dp[i][j]=0;
                    continue;
                }
                int l=0;
                if(i>0) l+=dp[i-1][j];
                if(j>0) l+=dp[i][j-1];
                dp[i][j]=l;
            }
        }
        return dp[m-1][n-1];
    }
};
