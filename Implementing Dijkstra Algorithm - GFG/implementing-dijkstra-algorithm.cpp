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
        // TC : ElogV
        //      E is total number of edges V i total no of nodes
        // Priority queue is used because we always want ot work on minim un distance first
        // vector<int> dist(V,INT_MAX);
        // min heap
    //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    //     q.push({0,S});
    //     dist[S]=0;
    //     while(!q.empty()){
    //         int dis=q.top().first;
    //         int node = q.top().second;
    //         q.pop();
            
    //         for(auto i:adj[node]){
    //             if(dist[i[0]] > dis+i[1]){
    //                 dist[i[0]]=dis+i[1];
    //                 q.push({dis+i[1],i[0]});
    //             }
    //         }
    //     }
    //     return dist;
    
    // Method 2 : using Set
    set<pair<int,int>> s;
    s.insert({0,S});
    vector<int> dist(V,INT_MAX);
    dist[S]=0;
    while(!s.empty()){
        auto it=*(s.begin());
        int dis=it.first;
        int node=it.second;
        s.erase(it);
        
        for(auto i:adj[node]){
            if(dis+i[1] < dist[i[0]]){
                dist[i[0]]=dis+i[1];
                s.insert({dis+i[1],i[0]});
            }
        }
    }
    return dist;
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