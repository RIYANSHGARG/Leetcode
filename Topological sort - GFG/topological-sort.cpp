//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &s){
	    vis[node]=1;
	    for(auto i:adj[node]){
	        if(!vis[i]) dfs(i,vis,adj,s);
	    }
	    s.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	    // Method 1 : topological sort
	    // if there is any edge between u and v then always u will appears before u and v in a linear order.
	    // only valid in DAG (directed and acyclic graphs)
	    
	    // stack<int> s;
	    // vector<int> vis(V,0),ans;
	    // for(int i=0;i<V;i++){
	    //     if(!vis[i]) dfs(i,vis,adj,s);
	    // }
	    // while(!s.empty()){
	    //     ans.push_back(s.top());
	    //     s.pop();
	    // }
	    // return ans;
	   
	    // Method 2 : Kahn's Algorithm (Using BFS)
	    // Indegree -> number of incoming edges for a node
	    // inserting all nodes with indegree 0
	    
	    // calculating indegrees
	    vector<int> indeg(V,0);
	    for(int i=0;i<V;i++){
	        for(auto j:adj[i]){
	            indeg[j]++;
	        }
	    }
	    queue<int> q;
	    vector<int> topo;
	    for(int i=0;i<indeg.size();i++){
	        if(indeg[i]==0) q.push(i);
	    }
	    while(!q.empty()){
	        int node=q.front();
	        topo.push_back(node);
	        q.pop();
	        for(auto i:adj[node]){
	            indeg[i]--;
	            if(indeg[i]==0) q.push(i);
	        }
	    }
	    return topo;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends