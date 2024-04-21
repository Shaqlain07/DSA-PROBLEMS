class Solution {
public:
    int dfs(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mat=INT_MIN;
        int not_mat=INT_MIN;
        if(text1[i]==text2[j]) {
            mat=1+dfs(i-1,j-1,text1,text2,dp);
        }
        else {
            not_mat=max(dfs(i-1,j,text1,text2,dp),
            dfs(i,j-1,text1,text2,dp));
        }
        return dp[i][j]=max(mat, not_mat);

    }
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        // return dfs(text1.size()-1,text2.size()-1,text1, text2,dp);

        // approach..have 2d vector where store all common subsequence
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=1;i<=text1.size();i++) {
            for(int j=1;j<=text2.size();j++) {
                if(text1[i-1]==text2[j-1]) {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }

        }
        return dp[text1.size()][text2.size()];

    }
};
