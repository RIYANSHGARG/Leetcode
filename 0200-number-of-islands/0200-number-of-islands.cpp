class Solution {
public:
    bool valid(int newrow,int newcol,vector<vector<char>> &grid, vector<vector<bool>> &vis){
        if(newrow>=0 && newrow <grid.size() && newcol>=0 && newcol <grid[0].size() && grid[newrow][newcol]=='1' && vis[newrow][newcol]==false){
            return true;
        }
        return false;
    }
    
    void bfs(vector<vector<char>> &grid , int r,int c, vector<vector<bool>> &vis){
        queue<pair<int,int>> q;
        q.push({r,c});
        vis[r][c]=true;
        while(!q.empty()){
            int i=q.front().first,j=q.front().second;
            q.pop();
            
            // Best method to traverse every neighbours 
            
            if(valid(i-1,j,grid,vis)){
                vis[i-1][j]=true;
                q.push({i-1,j});
            }
            if(valid(i,j-1,grid,vis)){
                vis[i][j-1]=true;
                q.push({i,j-1});
            }
            if(valid(i,j+1,grid,vis)){
                vis[i][j+1]=true;
                q.push({i,j+1});
            }
            if(valid(i+1,j,grid,vis)){
                vis[i+1][j]=true;
                q.push({i+1,j});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),count=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]=='1' && vis[i][j]==false){
                    cout<<i<<" "<<j<<endl;
                    bfs(grid,i,j,vis);
                    count++;
                }
            }
        }
        
        for(auto i:vis){
            for(auto j:i)   cout<<j<<" ";
            cout<<endl;
        }
        
        return count;
    }
};