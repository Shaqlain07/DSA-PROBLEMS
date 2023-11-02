class Solution {
public:
    //works only for possitive integer
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0;i<nums.size();i++) {
            totalSum+=nums[i];
        }
        vector<vector<int>> dp(n+1,vector<int>(totalSum+1,false));
        for(int i=0;i<=n;i++) {
            dp[i][0]=true;
        }
        //for every index we are storing with every target
        for(int i=n-1;i>=0;i--) {
            for(int j=1;j<=totalSum;j++) {
                bool skip=dp[i+1][j];
                bool take=false;
                if(j>=nums[i]) {
                    take=dp[i+1][j-nums[i]];
                }
                dp[i][j]=skip || take;
            }
        }
        int mn=INT_MAX;
        for(int i=0;i<=totalSum;i++) {
            if(dp[n-1][i]==true) {
                mn=min(mn,abs((totalSum-i)-i));
            }
        }
        return mn;
    }
};
