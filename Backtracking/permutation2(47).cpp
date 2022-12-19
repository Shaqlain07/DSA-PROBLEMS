class Solution {
public:
    unordered_map<int,int> mp;
    vector<vector<int>> ans;

    void permutation(int n,vector<int> v) {
        //base case
        if(v.size()==n) {
            ans.push_back(v);
            return;
        }
        //iterate on map..unique elements on nums
        for(auto &[key,val]:mp) {
            if(val<=0) {
                continue;
            }
                v.push_back(key);
                val--;

                permutation(n,v);
                //backtrack
               v.pop_back();
                val++;
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]]++;
        }
        permutation(nums.size(),v);
        return ans;
    }
};
