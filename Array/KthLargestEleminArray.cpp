class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //sort in decending order
        sort(nums.begin(), nums.end(), greater <>());

        int i=0;
        int ans;
        while(k!=0) {
            ans=nums[i];
            i++;
            k--;
        }
        return ans;
    }
};
