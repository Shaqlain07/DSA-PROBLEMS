class Solution {
public:
    int helper(int target,vector<int> &nums,vector<int>& dp) {
        //base case
        if(target==0) return 1;
        int ans=0;
        if(dp[target]!=-1) return dp[target];
        for(int i=0;i<nums.size();i++) {
            if(target-nums[i]>=0) {
                ans+=helper(target-nums[i],nums,dp);
            }
            else {
                break;
            }
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> dp(target+1,-1);
    
        return helper(target,nums,dp);
    }
};
