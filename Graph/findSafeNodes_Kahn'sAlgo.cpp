class Solution {
public:
    //Using kahn's algo..BFS
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //we need to reverse the edges of graph
        int v=graph.size();
        vector<int> adj[v];
        for(int i=0;i<graph.size();i++) {
            //i->it
            //it->i
            for(auto it:graph[i]) {
                adj[it].push_back(i);
            }
        }
        //put the indegree of all nodes and put it in vector
        vector<int> indeg(v,0);
        for(int i=0;i<v;i++) {
            for(auto it:adj[i]) {
                indeg[it]++;
            }
        }
        //Now,iterate on indegree vector and put it in queue whose indegree is 0
        queue<int> q;
        for(int i=0;i<v;i++) {
            if(indeg[i]==0) q.push(i);
        }
        vector<int> res;
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            for(auto it:adj[node]) {
                indeg[it]--;
                if(indeg[it]==0) {
                    q.push(it);
                }
            }
            res.push_back(node);
        }
        sort(res.begin(),res.end());
        return res;
    }
};
