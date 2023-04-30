class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)   return -1;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=1;
        vector<vector<int>> nrc={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        
        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            
            for(int i=0;i<8;i++){
                int newrow=row+nrc[i][0];
                int newcol=col+nrc[i][1];
                
                
                
                if(newrow>=0 && newrow<n && newcol >=0 && newcol<m && grid[newrow][newcol]==0 && dis+1<dist[newrow][newcol]){
                    if(newrow==n-1 && newcol==m-1)  return dis+1;
                    q.push({dis+1,{newrow,newcol}});
                    dist[newrow][newcol]=dis+1;
                }
            }
        }
        if(dist[n-1][m-1]==INT_MAX)  return -1;
        return dist[n-1][m-1];
    }
};