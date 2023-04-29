class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> nrc={{-1,0},{0,-1},{0,1},{1,0}};
        vector<vector<int>> vis(n,vector<int>(m,0)),dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    // dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            dist[row][col]=time;
            
            for(int i=0;i<4;i++){
                int newrow=row+nrc[i][0];
                int newcol=col+nrc[i][1];

                if(newrow>=0 && newrow<n && newcol >=0 && newcol<m && vis[newrow][newcol]!=1){
                    
                    q.push({{newrow,newcol},time+1});
                    vis[newrow][newcol]=1;
                    // dist[newrow][newcol]=time+1;
                }
            }
        }
        return dist;
    }
};