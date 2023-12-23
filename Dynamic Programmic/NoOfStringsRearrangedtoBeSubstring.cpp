class Solution {
public:
    const int mod=1e9+7;
    long long helper(int idx, int n, int l,int t, int e,long long dp[][2][2][3]) {
        //base case
        if(idx==n) {
            if(l>=1 && t>=1 && e>=2) {
                return 1;
            }
            return 0;
        }
        // check it is already present
        if(dp[idx][l][t][e]!=-1) {
            return dp[idx][l][t][e];
        }

        // try all possibilities from a-z
        long long res=0;
        for(char ch='a';ch<='z';ch++) {
            if(ch=='l' && l<1) {
                res=(res+helper(idx+1,n,l+1,t,e,dp))%mod;
            }
            else if(ch=='t' && t<1) {
                res=(res+helper(idx+1,n,l,t+1,e,dp))%mod;
            }
            else if(ch=='e' && e<2) {
                res=(res+helper(idx+1,n,l,t,e+1,dp))%mod;
            }
            else {
                res=(res+helper(idx+1,n,l,t,e,dp))%mod;
            }
        }
        return dp[idx][l][t][e]=res;
    }
    int stringCount(int n) {
        //create a dp
        long long dp[100001][2][2][3];
        memset(dp,-1,sizeof(dp));
        return (int)helper(0,n,0,0,0,dp);
    }
};
