class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int> &vis,vector<int> &pathVis,vector<int> &safeNode) {
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:graph[node]) {
            if(!vis[it]) {
                if(dfs(it,graph,vis,pathVis,safeNode)) return true;
            }
            else if(pathVis[it]) {
                return true;
            }
        }
        safeNode[node]=1;
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int> vis(m,0);
        vector<int> pathVis(m,0);
        vector<int> safeNode(m,0);
        for(int i=0;i<m;i++) {
            if(!vis[i]) {
                dfs(i,graph,vis,pathVis,safeNode);
            }
        }
        vector<int> res;
        for(int i=0;i<m;i++) {
            if(safeNode[i]==1) res.push_back(i);
        }
        return res;
    
    }
};
