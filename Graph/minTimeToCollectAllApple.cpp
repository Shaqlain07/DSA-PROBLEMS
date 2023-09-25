class Solution {
public:
    void dfs(int node,vector<int>& visited,vector<vector<int>> adj) {

            visited[node]=1;
            for(auto it:adj[node]) {
                if(visited[it]!=1) {
                    dfs(it,visited,adj);
                }
            }
        }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<isConnected.size();i++) {
            for(int j=0;j<isConnected[0].size();j++) {
                if(i!=j && isConnected[i][j]==1) {
                    adj[i].push_back(j);
                }
            }
        }
        
        int cnt=0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++) {
            if(visited[i]==0) {
                dfs(i,visited,adj);
                cnt++;
            }
        }
        return cnt;
    }
};
