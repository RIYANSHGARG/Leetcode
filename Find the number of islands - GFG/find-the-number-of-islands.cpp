//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void bfs(vector<vector<char>> &grid , int r,int c, vector<vector<bool>> &vis){
        queue<pair<int,int>> q;
        q.push({r,c});
        vis[r][c]=true;
        while(!q.empty()){
            int i=q.front().first,j=q.front().second;
            q.pop();
            
            // Best method to traverse every neighbours 
            
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int newrow = i+delrow;
                    int newcol = j+delcol;
                    
                    if(newrow>=0 && newrow <grid.size() && newcol>=0 && newcol <grid[0].size() && grid[newrow][newcol]=='1' && vis[newrow][newcol]==false){
                        vis[newrow][newcol]=true;
                        q.push({newrow,newcol});
                    }
                }
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),count=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]=='1' && vis[i][j]==false){
                    bfs(grid,i,j,vis);
                    count++;
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends