class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int start=0;//starting of increasing subarray
        int end=0;
        int ans=1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]>nums[end]) {
                end=i;
                ans=max(ans,end-start+1);
            }
            else {
                end=i;
                start=i;
            }
        }
        return ans;
    }
};
