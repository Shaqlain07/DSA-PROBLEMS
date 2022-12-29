class Solution {
public:
    bool helper(int index,vector<int>& nums,int dp[]) {
        //base case
        if(index==nums.size()-1) {
            return true;
        }
        if(index>=nums.size()) return false;
        //check if it is available earlier
        if(dp[index]!=-1) {
            return dp[index];
        }
        //calculate,save and return
        for(int j=1;j<=nums[index];j++) {
            if(helper(index+j,nums,dp)) {
                return dp[index]=true;
            }
        }
        return dp[index]=false;
    }
    bool canJump(vector<int>& nums) {
        int dp[nums.size()];
        for(int i=0;i<nums.size();i++) {
            dp[i]=-1;
        }
        return helper(0,nums,dp);
    }
};
