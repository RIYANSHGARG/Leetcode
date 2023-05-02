class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Testcase : 
        // 5
        // [[0,1,5],[1,2,5],[0,3,2],[3,1,2],[1,4,1],[4,2,1]]
        // 0
        // 2
        // 2
        // We cannot take priority queue on the basis of distance because our major concern is stops that it should not exceed maximum number of stops. 
        // So we will make a queue {stops , node , dist}    dont need priority queue because we are increasing stops by 1.
        
//         int m=flights.size();
//         vector<pair<int,int>> adj[n];
//         for(int i=0;i<m;i++){
//             adj[flights[i][0]].push_back( {flights[i][1],flights[i][2]});
//         }
        
//         vector<int> dist(n,INT_MAX);
//         dist[src]=0;
        
//         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
//         // dist, node , stops
//         pq.push({0,{src,0}});
                 
//         while(!pq.empty()){
//             int dis=pq.top().first;
//             int node = pq.top().second.first;
//             int stops= pq.top().second.second;
//             pq.pop();
            
//             if(stops>k) continue;
//             // if(node == dst)    return dis;
            
//             for(auto i:adj[node]){
//                 int newdist = dis+i.second;
//                 int adjnode = i.first;
                
//                 if(newdist < dist[adjnode] && stops<k){
//                     dist[adjnode]=newdist;
//                     pq.push({newdist,{adjnode,stops+1}});
                    
//                 }
//                 else if(newdist < dist[adjnode] && stops==k){
//                     dist[adjnode]=newdist;
//                     pq.push({newdist,{adjnode,stops+1}});
//                     break;
//                 }
//             }
//         }
//         for(auto i:dist)    cout<<i;
//         if(dist[dst]==INT_MAX)  return -1;
//         return dist[dst];
            
        
        // Actual method 
        int m=flights.size();
        vector<pair<int,int>> adj[n];
        for(int i=0;i<m;i++){
            adj[flights[i][0]].push_back( {flights[i][1],flights[i][2]});
        }
        
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        
        queue<pair<int,pair<int,int>>> pq;
        // stops, node , dist
        pq.push({0,{src,0}});
                 
        while(!pq.empty()){
            int stops=pq.front().first;
            int node = pq.front().second.first;
            int dis= pq.front().second.second;
            pq.pop();
            
            if(stops>k) continue;
            
            for(auto i:adj[node]){
                int newdist = dis+i.second;
                int adjnode = i.first;
                
                if(newdist < dist[adjnode] && stops<=k){
                    dist[adjnode]=newdist;
                    pq.push({stops+1,{adjnode,newdist}});
                }
            }
        }
        if(dist[dst]==INT_MAX)  return -1;
        return dist[dst];
    }
};