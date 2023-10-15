//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &vis,vector<pair<int,int>> &v,int startR,int startC){
        
        int m=grid.size();
        int n=grid[0].size();
        v.push_back({i-startR,j-startC});
        int deltaR[]={-1,0,1,0};
        int deltaC[]={0,1,0,-1};
        for(int k=0;k<4;k++) {
            int newR=i+deltaR[k];
            int newC=j+deltaC[k];
            
            if(newR>=0 && newR<m && newC>=0 && newC<n && !vis[newR][newC] && grid[newR][newC]==1){
                vis[newR][newC]=1;
                
                dfs(newR,newC,grid,vis,v,startR,startC);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m=grid.size();
        int n=grid[0].size();
        set<vector<pair<int,int>>> s;

        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                
                if(!vis[i][j] && grid[i][j]==1) {
                    vector<pair<int,int>> v;
                    vis[i][j]=1;
                    dfs(i,j,grid,vis,v,i,j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
