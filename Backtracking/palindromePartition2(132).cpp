class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> dp1;
    bool isPalindrome(string& s, int i, int j) {
		if (i >= j) return true;
		if (dp1[i][j] != -1) return dp1[i][j];
		if (s[i] == s[j]) return dp1[i][j] = isPalindrome(s, i + 1, j - 1);
		return dp1[i][j] = false;
	}
    int solve(string &s,int i,int e) {
        //base case
        if(i>e) {
            return 0;
        }
        int count=INT_MAX;
        if(dp[i][e]!=-1) return dp[i][e];
        for(int j=i;j<s.size();j++) {
            //check for palindrome
            if(isPalindrome(s,i,j)) {
                count=min(count,solve(s,j+1,e)+1);
            }
        }
        return dp[i][e]=count;
    }
    int minCut(string s) {
        
        dp.resize(s.size(),vector<int> (s.size(),-1));
        dp1.resize(s.size(),vector<int> (s.size(),-1));
        return solve(s,0,s.size()-1)-1;
        
    }
};
