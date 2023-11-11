class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    
    // void dfs(int i, vector<int> &vis, vector<vector<pair<int,int>>> &adjc,stack<int> &s){
    //     vis[i]=1;
    //     for(auto j:adjc[i]){
    //         int v=j.first;
    //         if(!vis[v]) dfs(v,vis,adjc,s);
    //     }
    //     s.push(i);
    // }
    
    int dijkstra(int start, int end) {
        vector<vector<pair<int,int>>> adjacencyList=adj;
        int n = adjacencyList.size();
        vector<int> distances(n, INT_MAX);
        distances[start] = 0;

        // Priority queue to efficiently retrieve the node with the minimum distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorityQueue;
        priorityQueue.push({0, start});

        while (!priorityQueue.empty()) {
            int currentNode = priorityQueue.top().second;
            int currentCost = priorityQueue.top().first;
            priorityQueue.pop();

            // Skip if a shorter path has already been found
            if (currentCost > distances[currentNode])
                continue;

            // If found the target node then return the cost
            if(currentNode == end)
                return currentCost ;

            // Explore neighbors and update distances
            for (auto edge : adjacencyList[currentNode]) {
                int neighbor = edge.first, edgeLength = edge.second;
                int newRouteCost = edgeLength + distances[currentNode];

                // Update distance if a shorter route is found
                if (distances[neighbor] > newRouteCost) {
                    distances[neighbor] = newRouteCost;
                    priorityQueue.push({newRouteCost, neighbor});
                }
            }
        }

        // Return the minimum distance or -1 if no path exists
        return ((distances[end] == INT_MAX) ? -1 : distances[end]);
    }

    
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        // for(int i=0;i<adj.size();i++){
        //     for(int j=0;j<adj[i].size();j++){
        //         cout<<i<<" "<<adj[i][j].first<<" "<<adj[i][j].second<<endl;
        //     }
        // }
//         int mod = 1e9;
//         stack<int> s;
//         vector<int> vis(adj.size(),0);
        
//         for(int i=0;i<adj.size();i++){
//             if(!vis[i]) dfs(i,vis,adj,s);
//         }
        
//         vector<int> dis(adj.size(),1e9);
//         dis[node1]=0;
        
//         while(!s.empty()){
//             int node = s.top();
//             s.pop();
            
//             for(auto j:adj[node]){
//                 int v = j.first;
//                 int wt = j.second;
                
//                 if((dis[node]+wt)%mod < dis[v]){
//                     dis[v]=dis[node]+wt;
//                 }
//             }
//         }
//         if(dis[node2]==1e9) return -1;
//         return dis[node2];
        return dijkstra(node1,node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */