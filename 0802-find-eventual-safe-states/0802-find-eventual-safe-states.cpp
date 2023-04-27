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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[graph.size()];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> vis(n,0),pathvis(n,0),incycle(n,0),ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,adj,incycle);
            }
        }
        for(auto i=0;i<incycle.size();i++){
            if(incycle[i]==1)   ans.push_back(i);
        } 
        sort(ans.begin(),ans.end());
        return ans;
    }
};