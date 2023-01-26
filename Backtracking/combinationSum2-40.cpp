class Solution {
public:
    void combination(vector<int>& nums,int index,int target,vector<int> curr,vector<vector<int>> &ans) {
        //base case
        if(target==0) {
            ans.push_back(curr);
            return;
        }
        if(target<0 || index>=nums.size()) return;
        
        //picking that index
        curr.push_back(nums[index]);
        combination(nums,index+1,target-nums[index],curr,ans);
        //backtrack..pop the curr element
        curr.pop_back();
        //not picking that index..move that index which are not equal to current index
        //skip the duplicates
        while(index+1<nums.size() && nums[index]==nums[index+1]) {
            index+=1;
        }
        combination(nums,index+1,target,curr,ans);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        combination(candidates,0,target,curr,ans);
        return ans;
    }
};
