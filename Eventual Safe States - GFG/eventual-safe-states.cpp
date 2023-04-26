//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    bool dfs(int node, vector<int> &vis, vector<int> &pathvis ,vector<int> adj[],vector<int> &incycle){
        vis[node]=1;
        pathvis[node]=1;
        incycle[node]=0;
        
        for(auto i:adj[node]){
            if(!vis[i] )    {if(dfs(i,vis,pathvis,adj,incycle))   {incycle[node]=0;return true;}}
            else if(pathvis[i]) {
                incycle[node]=0;
                return true;
            }
        }
        
        incycle[node]=1;
        pathvis[node]=0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int n=V;
        vector<int> vis(n,0),pathvis(n,0),incycle(n,0),ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,adj,incycle);
            }
        }
        for(auto i=0;i<incycle.size();i++){
            if(incycle[i]==1)   ans.push_back(i);
        } 
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends