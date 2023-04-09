class Solution {
public:
    void solve(vector<int> &nums,vector<int> curr,vector<vector<int>> &res,int i) {
        //base case
        if(i==nums.size()) {
            res.push_back(curr);
            return;
        }
        //not included
        int j=i;
        while(j<nums.size() && nums[i]==nums[j]) {
            j++;
        }
        solve(nums,curr,res,j);
        //included
        curr.push_back(nums[i]);
        solve(nums,curr,res,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        solve(nums,curr,res,0);
        return res;
    }
};
