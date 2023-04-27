class Solution {
public:
    
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
    
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        vector<int> adj[N];
	    for(int i=0;i<prerequisites.size();i++){
	        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
	    }
	    
        // Method 1 : using BFS and Topo sort
	    // vector<int> topo,indegree(N,0);
	    // queue<int> q;
	    // for(int i=0;i<N;i++){
	    //     for(auto j:adj[i]){
	    //         indegree[j]++;
	    //     }
	    // }
	    // for(int i=0;i<N;i++)    if(indegree[i]==0)  q.push(i);
	    // while(!q.empty()){
	    //     int node=q.front();
	    //     q.pop();
	    //     topo.push_back(node);
	    //     for(auto i:adj[node]){
	    //         indegree[i]--;
	    //         if(indegree[i]==0)  q.push(i);
	    //     }
	    // }
	    // return (topo.size()==N);
        
        // Method 2 : using DFS (detecting cycle)
        vector<int> vis(N,0),pathvis(N,0);
        for(int i=0;i<N;i++){
            if(!vis[i] && dfs(i,vis,pathvis,adj)==true)   return false;
        }
        return true;
    }
};