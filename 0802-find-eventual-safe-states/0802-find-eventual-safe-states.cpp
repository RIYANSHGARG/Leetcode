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
    
    // method 2 functions
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        // Method 1 : using DFS and checking that if it is in cycle or not
        int n=graph.size();
        // adj matrix to adj list
        vector<int> adj[graph.size()];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        // calling dfs
        // vector<int> vis(n,0),pathvis(n,0),incycle(n,0),ans;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         dfs(i,vis,pathvis,adj,incycle);
        //     }
        // }
        // all those who are terminal are being pushed to ans
        // for(auto i=0;i<incycle.size();i++){
        //     if(incycle[i]==1)   ans.push_back(i);
        // } 
        // sort(ans.begin(),ans.end());
        // return ans;
        
        // Mehtod 2 : using BFS : Topological sort 
        
        // intution is terminal nodes ... all those whose outdegree is 0 are terminal nodes ...
        // so these nodes are part of ans.
        // reverseing the graph and all out degrees converted to indegree and now basically add all 
        // nodes that are having indegree 0;
        vector<int> adjrev[n];
        vector<int> indegree(n,0),ans;
        queue<int> q;
        
        // Reversing vector and adding indegree
        for(int i=0;i<n;i++){
            for(auto j:adj[i]){
                adjrev[j].push_back(i);
                indegree[i]++;
            }
        }
        
        // putting all those nodes whose indegree in 0 in queue
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:adjrev[node]){
                indegree[i]-=1;
                if(!indegree[i])    q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};