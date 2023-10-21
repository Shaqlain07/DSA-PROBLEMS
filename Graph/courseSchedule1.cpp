class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        //create an adjecency list
        //where u will be performed first then v
        //this is oppossite to the question
        //so we will store the pair in reverse order
        vector<int> adj[V];
        for(auto it:prerequisites) {
            adj[it[1]].emplace_back(it[0]);
        }
        //create an indegree vector which will store all
        //the indegree of node
        vector<int> indeg(V,0);
        for(int i=0;i<V;i++) {
            for(auto it:adj[i]) {
                indeg[it]++;
            }
            
        } 
        queue<int> q;
        vector<int> res;
        //put all the nodes to queue to whose indeg is 0
        for(int i=0;i<V;i++) {
            if(indeg[i]==0) q.push(i);
        }
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
        if(res.size()!=V) return false;
        return true;
    }
};
