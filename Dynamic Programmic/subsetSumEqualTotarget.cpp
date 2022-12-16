//User function template for C++

class Solution{   
public:
    bool helper(vector<int> &arr,int target,int idx,vector<vector<int>> &dp) {
        //base case
        if(target==0) return true;
        if(idx==0) return (arr[0]==target);
        //check
        if(dp[idx][target]!=-1) return dp[idx][target];
        //calculate
        bool nottaken=helper(arr,target,idx-1,dp);
        bool taken=false;
            if(target>=arr[idx]) {
                taken=helper(arr,target-arr[idx],idx-1,dp);
            }
        //save and return
        return dp[idx][target]=nottaken | taken;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return helper(arr,sum,n-1,dp);
        // code here 
    }
};
