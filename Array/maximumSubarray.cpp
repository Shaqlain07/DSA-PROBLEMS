class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=nums[0];
        int mx=nums[0];
        
        for(int i=1;i<nums.size();i++) {
            if(curr+nums[i] > nums[i]) {
                curr+=nums[i];
            }
            else {
                curr=nums[i];
            }
            mx=max(mx,curr);
        }
        return mx;
    }
};
