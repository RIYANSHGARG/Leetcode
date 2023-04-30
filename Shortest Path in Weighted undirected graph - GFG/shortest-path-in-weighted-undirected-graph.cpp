//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<int> parent,dist(n+1,INT_MAX);
        dist[1]=0;
        for(int i=0;i<=n;i++)   parent.push_back(i);
        
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,1});
        // cout<<1;
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto i:adj[node]){
                int adjnode=i.first;
                int adjweight=i.second;
                if(dis+adjweight < dist[adjnode]){
                    dist[adjnode]=dis+adjweight;
                    pq.push({dis+adjweight,adjnode});
                    parent[adjnode]=node;
                }
            }
        }
        // for(auto i:parent)  cout<<i;
        if(dist[n]>=INT_MAX-1)    return {-1};
        vector<int> ans;    
        while(parent[n]!=n){
            ans.push_back(n);
            n=parent[n];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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