class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        int curr=0;
        mp[curr]++;
        for(int i=0;i<nums.size();i++) {
            curr+=nums[i];
            int diff=curr-target;
            if(mp.find(diff)!=mp.end()) {
                return true;
            }
            mp[curr]++;
        }
        return false;
    }
};
