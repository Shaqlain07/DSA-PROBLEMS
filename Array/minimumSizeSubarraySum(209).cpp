class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res=INT_MAX;//length of subarray
        int left=0;//left iterator
        int sum=0;//to get prefix sum

        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            while(sum>=target) {
                res=min(res,i-left+1);
                sum-=nums[left++];
            }
        }
        if(res==INT_MAX) return 0;
        return res;
    }
};
