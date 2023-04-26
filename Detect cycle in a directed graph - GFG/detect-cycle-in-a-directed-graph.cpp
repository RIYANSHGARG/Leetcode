//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int> &vis, vector<int> &pathvis, vector<int> adj[]){
        vis[node]=1;pathvis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(dfs(i,vis,pathvis,adj)==true)    return true;
            }
            else if(pathvis[i]) return true;
        }
        pathvis[node]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        // Mehtod 1 : using DFS
        // vector<int> vis(V,0),pathvis(V,0); 
        // for(int i=0;i<V;i++){
        //     if(!vis[i] && dfs(i,vis,pathvis,adj)==true )    return true;
        // }
        // return false;
        
        // Method 2 : using BFS (topological sort)(kahn's algorithm)(indegree)
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int> q;
	    vector<int> topo;
	    for(int i=0;i<indegree.size();i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto i:adj[node]){
	            indegree[i]--;
	            if(indegree[i]==0)  q.push(i);
	        }
	    }
	    return !(topo.size()==V);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends