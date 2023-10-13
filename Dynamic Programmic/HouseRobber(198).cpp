vector<int> dp(nums.size(),-1);
    dp[0]=nums[0];
    for(int i=1;i<nums.size();i++) {
        //not pick
        int nottake=dp[i-1];
        //pick
        int take=nums[i];
        if(i>1) take+=dp[i-2];
        dp[i]=max(take,nottake);
    }
    return dp[nums.size()-1];
