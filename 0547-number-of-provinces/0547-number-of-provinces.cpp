class Solution {
public:
    
    void dfs(int node, vector<int> adj[], int vis[]){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]) {vis[i]=1;dfs(i,adj,vis);}
        }
        
    }
    
    // void dfsHelper( vector<int> adj[], int &count, int n){
    //     int vis[n];
    //      for(int i=0;i<n;i++)    vis[i]=0;
    //     for(int i=0;i<n;i++){
    //         if(!vis[i]){
    //             count++;
    //             dfs(i,adj,vis);
    //         }
    //     }
    // }
    
    int findCircleNum(vector<vector<int>>& isConnected){
        int count=0;
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        // dfsHelper(adj,count,isConnected.size());
        int vis[n];
        for(int i=0;i<n;i++)    vis[i]=0;
        for(int i=0;i<n;i++){
            if(vis[i]!=1)   {dfs(i,adj,vis);count++;}
        }
        
        return count;
    }
};