class Solution {
public:
    //memoization
    //t.c-O(n*m)
    //s.c-O(n*m)+O(n+m)
    int solve(string &s1,string &s2,int idx1,int idx2,vector<vector<int>> &dp) {
        //base case
        if(idx1<0 || idx2<0) return 0;
        //compare character by character
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s1[idx1]==s2[idx2]) {
           return dp[idx1][idx2]=1+solve(s1,s2,idx1-1,idx2-1,dp);
        }
        return dp[idx1][idx2]=max(solve(s1,s2,idx1-1,idx2,dp),solve(s1,s2,idx1,idx2-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        //length of common subsequence upto i,j
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(text1,text2,text1.size()-1,text2.size()-1,dp);
    }
};
