class Solution {
public:
    bool isValid(int mid,vector<int> &nums) {
        long preSum=0;
        for(int i=0;i<nums.size();i++) {
            preSum+=nums[i];
            if(preSum>((long)mid*(i+1))) return false;
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        //range in which we can change our max element
        int left=0, right=*max_element(nums.begin(),nums.end());
        while(left<right) {
            int mid=(left+right)/2;
            if(isValid(mid,nums)) {
                right=mid;//now we are decreasing the value
            }
            else {
                left=mid+1;
            }
        }
        return left;

    }
};
