#include <bits/stdc++.h>
//memoization
bool dfs(int i,vector<int> &arr,int target,vector<vector<int>> &dp) {
    if(i==arr.size()) {
        if(target==0) return true;
        return false;
    }
    //if(target<0) return false;
    if(target==0) return true;

    if(dp[i][target]!=-1) return dp[i][target];

    //not pick
    bool a=dfs(i+1,arr,target,dp);
    //pick
    bool b=false;
    if(target-arr[i]>=0) {
        b=dfs(i+1,arr,target-arr[i],dp);
    }
    return dp[i][target]=a || b;
} 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n+1,vector<int>(k+1,false));
    // dfs(0,arr,k,dp);

    //tabulation
    //base case for tabulation
    for(int i=0;i<=n;i++) {
        dp[i][0]=true;
    }
    //for every index we are storing with every target
    for(int i=n-1;i>=0;i--) {
        for(int j=1;j<=k;j++) {
            bool skip=dp[i+1][j];
            bool take=false;
            if(j>=arr[i]) {
                take=dp[i+1][j-arr[i]];
            }
            dp[i][j]=skip || take;
        }
    }
    return dp[0][k];
    
}
