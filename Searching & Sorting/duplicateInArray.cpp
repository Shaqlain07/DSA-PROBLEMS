class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int ans;
        for(int i=0;i<nums.size();i++) {
            if(mp.find(nums[i])!=mp.end()) {
                ans= nums[i];
                break;
            }
            else {
                mp[nums[i]]=true;
            }
        }
        return ans;
    }
};
