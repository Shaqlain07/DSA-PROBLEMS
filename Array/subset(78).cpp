class Solution {
public:
    void solve(vector<int> &nums,vector<int> curr,vector<vector<int>> &res,int i) {
        if(i==nums.size()) {
            res.push_back(curr);
            return;
        }
        //the index is not included
        solve(nums,curr,res,i+1);
        //included
        curr.push_back(nums[i]);
        solve(nums,curr,res,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(nums,curr,res,0);
        return res;
    }
};
