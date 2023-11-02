//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	    // Your code goes here
	   
        int totalSum=0;
        for(int i=0;i<n;i++) {
            totalSum+=nums[i];
        }
        vector<vector<int>> dp(n+1,vector<int>(totalSum+1,false));
        for(int i=0;i<=n;i++) {
            dp[i][0]=true;
        }
        //for every index we are storing with every target
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=totalSum;j++) {
                bool skip=dp[i-1][j];
                bool take=false;
                if(j>=nums[i-1]) {
                    take=dp[i-1][j-nums[i-1]];
                }
                dp[i][j]=skip || take;
            }
        }
        int mn=INT_MAX;
        for(int i=0;i<=totalSum;i++) {
            if(dp[n-1][i]==true) {
                mn=min(mn,abs((totalSum-i)-i));
            }
        }
        return mn;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
