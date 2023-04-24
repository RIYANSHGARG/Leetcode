//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int node,int c, vector<int> &vis ,vector<int> &color, vector<int> adj[]){
        vis[node]=1;
        color[node]=c;
        
        for(auto i:adj[node]){
            if(!vis[i] && !dfs(i,!c,vis,color,adj))  return false;
            else if(color[i]==c)    return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> vis(V,0),color(V,-1);
	    for(int i=0;i<V;i++){
	        if(!vis[i] && !dfs(i,0,vis,color,adj))   return false; 
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends