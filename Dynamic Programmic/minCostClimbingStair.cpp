class Solution {
public:
    int minimumCostMemoized(int n, vector<int> &cost, vector<int> &dp)
{
    if (n == 0)
        return cost[0];
    if (n == 1)
        return cost[1];
    if (dp[n] != -1)
        return dp[n];
    dp[n] = min(minimumCostMemoized(n - 1, cost, dp) + cost[n],
                minimumCostMemoized(n - 2, cost, dp) + cost[n]);
    return dp[n];
}
    int minCostClimbingStairs(vector<int>& cost) {
         int n = cost.size();
    vector<int> dp(n + 1, -1);
    int ans = min(minimumCostMemoized(n - 2, cost, dp), minimumCostMemoized(n - 1, cost, dp));
    return ans;
    }
};
