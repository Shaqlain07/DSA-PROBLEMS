//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        int mn=0;
        int buy=0;
        int free=N-1;
        while(buy<=free) {
            mn+=candies[buy];
            buy++;
            free-=K;
        }
        int mx=0;
        reverse(candies,candies+N);
        buy=0;
        free=N-1;
        while(buy<=free) {
            mx+=candies[buy];
            buy++;
            free-=K;
        }
        vector<int> res;
        res.push_back(mn);
        res.push_back(mx);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends
