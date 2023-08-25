class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int res=0;
        int mn=nums[0];
        for(int i=1;i<nums.size();i++) {
            if(nums[i]-mn>0) {
                res=max(res,nums[i]-mn);
            }
            mn=min(mn,nums[i]);
        }
        return res;
    }
};
