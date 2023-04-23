//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row,int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int,int>> &v, int baserow , int basecol)
    {
        int n=grid.size(),m=grid[0].size();
        if(row<0 || row>=n || col<0 || col>=m || vis[row][col]==1 || grid[row][col]!=1)  {return;}
        vis[row][col]=1;
        v.push_back({row-baserow,col-basecol});
        dfs(row,col-1,grid,vis,v,baserow,basecol);
        dfs(row+1,col,grid,vis,v,baserow,basecol);
        dfs(row,col+1,grid,vis,v,baserow,basecol);
        dfs(row-1,col,grid,vis,v,baserow,basecol);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        // cout<<1;
        set<vector<pair<int,int>>> s;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    vector<pair<int,int>> v;
                    dfs(i,j,grid,vis,v,i,j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends