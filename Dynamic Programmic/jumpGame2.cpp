class Solution {
public:
    
    int helper(int index,vector<int>& nums,int dp[]) {
        //base case
        
        if(index==nums.size()-1) {
            return 0;
        }
        
        //check if it is available earlier
        if(dp[index]!=-1) {
            return dp[index];
        }
        int mn=1e9;
        //calculate,save and return
        for(int j=1;j<=nums[index];j++) {
            if(index+j<nums.size()) {
                int a=1+helper(index+j,nums,dp); 
                mn=min(mn,a);
            }  
        }
        return dp[index]=mn;
    }
    int jump(vector<int>& nums) {
        int dp[nums.size()];
        for(int i=0;i<nums.size();i++) {
            dp[i]=-1;
        }
        return helper(0,nums,dp);
    }
};
