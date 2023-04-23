class Solution {
    private : 
    bool bfs(int s,vector<int> &color, vector<int>&vis, vector<int> adj[]){
        queue<int> q;
        q.push(s);
        color[s]=1;
        vis[s]=1;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto i:adj[node]){
                if(color[i] == color[node] ) return false;
                else if(vis[i]==0){
                    q.push(i);
                    vis[i]=1;
                    color[i]=(!color[node]);
                }
            }
        }
        return true;
    }
    bool dfs(int s,int c, vector<int> &color, vector<int> &vis, vector<int> adj[]){
        // if(vis[s]==1 && color[s]!=c)    return false;
        // if(vis[s]==1 && color[s]==c)    return true; 
        vis[s]=1;
        color[s]=c;
        for(auto i:adj[s]){
            if(!vis[i] && dfs(i,!c,color,vis,adj)==false) return false;
            else if(color[i]==c)    return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> color(n,-1),vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                // if(bfs(i,0,color,vis,adj)==false)    {return false;}
                if(dfs(i,0,color,vis,adj)==false)    return false;
            }
        }
        return true;        
    }
};