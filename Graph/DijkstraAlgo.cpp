//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        //priority queue for minimum heap
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        //distance vector to store the minimum distance from src to diff node
        vector<int> dis(V);
        for(int i=0;i<V;i++) dis[i]=1e9;
        
        pq.push({0,S});
        dis[S]=0;
        while(!pq.empty()) {
            int ds=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]) {//have all edges connected to node
                int itWeight=it[1];
                int itNode=it[0];
                
                if(ds+itWeight<dis[itNode]) {// got min distance for it update
                    dis[itNode]=ds+itWeight;
                    pq.push({ds+itWeight,itNode});
                }
            }
        }
        return dis;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
