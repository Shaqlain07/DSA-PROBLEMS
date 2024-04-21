//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        // follow the steps for lcs
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
        int res=0;
        for(int i=1;i<=s1.size();i++) {
            for(int j=1;j<=s2.size();j++) {
                if(s1[i-1]==s2[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                    int temp=dp[i][j];
                    res=max(res,temp);
                }
                else {
                    dp[i][j]=0;
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
