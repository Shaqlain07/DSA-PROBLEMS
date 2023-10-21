class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        //our base case..from this index to last row min path is
        for(int i=0;i<m;i++) {
            dp[m-1][i]=triangle[m-1][i];
        }
        for(int i=m-2;i>=0;i--) {
            for(int j=0;j<=i;j++) {
                
                int sum1=dp[i+1][j];
                int sum2=dp[i+1][j+1];
                dp[i][j]=triangle[i][j]+min(sum1,sum2);
            }
        }
        
        return dp[0][0];
    }
};
