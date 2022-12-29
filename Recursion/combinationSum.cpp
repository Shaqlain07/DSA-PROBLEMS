class Solution {
public:
    void combination(vector<int>& nums,int index,int target,vector<int> curr,vector<vector<int>> &ans) {
        //base case
        if(target==0) {
            ans.push_back(curr);
            return;
        }

        if(target<0) {
            return;
        }
        if(index==nums.size()) return;

        combination(nums,index+1,target,curr,ans);//not picking
        curr.push_back(nums[index]);
        combination(nums,index,target-nums[index],curr,ans);// picking

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;//for returning answer
        vector<int> curr;
        combination(nums,0,target,curr,ans); 
        return ans;
    }
};
