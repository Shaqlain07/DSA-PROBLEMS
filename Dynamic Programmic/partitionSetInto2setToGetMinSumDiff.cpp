//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int total=0;
	    for(int i=0;i<n;i++) {
	        total+=arr[i];
	    }
	    // till index, can we acheive this particular target
	    vector<vector<int>> dp(n,vector<int>(total+1,false));
	    // if our target is 0 then for every index we can achieve the target by picking no element
	    for(int i=0;i<n;i++) dp[i][0]=true;
	    // if our index is at 0 then then we will check target is arr[0]
	    if(total>=arr[0]) dp[0][arr[0]]=true;
	    for(int i=1;i<n;i++) {
	        for(int j=1;j<=total;j++) {
	            // not take..so it will depend upon previous dp
	            bool not_take=dp[i-1][j];
	            // take
	            bool take=false;
	            if(j>=arr[i]) {
	                // we go to previous dp and decrese the target arr[i], then check
	                take=dp[i-1][j-arr[i]];
	            }
	            dp[i][j]=take|| not_take;
	        }
	    }
	    // interating on every target, 
	    int mn=INT_MAX;
	    for(int i=0;i<=total;i++) {
	        if(dp[n-1][i]==true) {
	            int s1=i;
	            int s2=total-s1;
	            mn=min(mn,abs(s1-s2));
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
