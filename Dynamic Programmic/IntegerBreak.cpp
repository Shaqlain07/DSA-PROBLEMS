class Solution {
public:
    int integerBreak(int n) {
       vector<int> dp(100,0);//strong max product of ith no
       dp[1]=1;
       dp[2]=1;
       dp[3]=2;

        for(int i=1;i<=n;i++) {
            for(int j=1;j<i;j++) {
                int x=j;
                int y=i-x;
                dp[i]=max({dp[i],x*y,dp[x]*y,dp[y]*x,dp[x]*dp[y]});
            }
        }
        return dp[n];
    }
};
