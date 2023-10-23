//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    void dfs(int node,vector<int> &vis,vector<pair<int,int>> adj[],stack<int> &st) {
        
        for(auto ptr:adj[node]) {
            int it=ptr.first;
            if(!vis[it]) {
                vis[it]=1;
                dfs(it,vis,adj,st);
            }
        }
        st.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        //create an adjancency matrix with its weight
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++) {
                adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        //do topo sort algo..bfs
        vector<int> vis(N,0);
        stack<int> st;
        
        for(int i=0;i<N;i++) {
            if(!vis[i]) {
                vis[i]=1;
                dfs(i,vis,adj,st);
            }
        }
        vector<int> dis(N,1e9);
        dis[0]=0;
        //put -1 for unreachable state since there is no incoming edges so it will be at front only
         /*for (int i = 0; i < N; i++) {
            if(st.top() !=  0){
                int node = st.top();
                st.pop();
                dis[node] = -1;
            }
            else {
                break;
                
            }
        }*/
        while(!st.empty()) {
            int node=st.top();
            st.pop();
            
                for(auto it:adj[node]) {
                int nd=it.first;
                int wt=it.second;
                
                if(dis[node]+wt<dis[nd]) {
                    dis[nd]=dis[node]+wt;
                }
                }    
            
            
        }
        for(int i=0;i<N;i++) {
            if(dis[i]==1e9) dis[i]=-1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
