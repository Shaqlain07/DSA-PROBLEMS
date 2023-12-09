class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int s=0;
        int len=0;
        unordered_map<int,int> mp;
        for(int e=0;e<nums.size();e++) {
            mp[nums[e]]++;
            
            while(mp[nums[e]]>k) {
                mp[nums[s]]--;
                s++;
            }
            len=max(len,e-s+1);
        }
        return len;
    }
};
