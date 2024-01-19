class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(i==matrix.size()) return 0;

        int m=matrix.size();
        // cal
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int sum=INT_MAX;
        if(j-1>=0) {
            sum=min(sum, matrix[i][j]+dfs(i+1, j-1, matrix, dp));
        }
        if(j+1<matrix.size()) {
            sum=min(sum, matrix[i][j]+dfs(i+1, j+1, matrix, dp));
        }
        sum=min(sum, matrix[i][j]+dfs(i+1, j, matrix, dp));
        return dp[i][j]=sum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int sum=INT_MAX;
        int m=matrix.size();
        vector<vector<int>> dp(m, vector<int>(m,INT_MAX));
        for(int i=0;i<matrix[0].size();i++) {
            sum=min(sum, dfs(0, i, matrix, dp));
        }
        return sum;
    }
};
