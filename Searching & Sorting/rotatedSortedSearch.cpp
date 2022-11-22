class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e) {
            int mid=(s+e)/2;
            if(nums[mid]==target) return mid;
            //check left element is shorted or not
            if(nums[mid]>=nums[s]) {
                
                //target element is on left or not
                if(target<nums[mid] && target>=nums[s] ) {
                    e=mid-1;
                }
                else {
                    s=mid+1;
                }
            }
            else {
                //check right element is shorted or not
                if(target>nums[mid] && target<=nums[e] ) {
                    s=mid+1;
                }
                else {
                    e=mid-1;
                }
            }
        }
        return -1;
    }
};
