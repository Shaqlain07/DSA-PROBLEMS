class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r) {
            int mid=l+(r-l)/2;
            if(nums[mid]==target) {
                return true;
            }
            else if(nums[l]==nums[mid] && nums[r]==nums[mid]) {//elements are repeating
                l++;
                r--;
            }
            else if(nums[l]<=nums[mid]) {//left side are sorted
                if(nums[l]<=target && nums[mid]>target ) {//target are on left side
                    r=mid-1;
                }
                else {//target on right side
                    l=mid+1;
                }
            }
            else {//right side are sorted
                if(nums[mid]<target && nums[r]>=target) {//target on right side
                    l=mid+1;
                }
                else {
                    r=mid-1;
                }
            }
        }
        return false;
    }
};
