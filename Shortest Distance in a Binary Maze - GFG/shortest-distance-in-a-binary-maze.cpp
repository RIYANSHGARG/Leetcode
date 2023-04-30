//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if(source.first==destination.first && source.second==destination.second)    return 0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[source.first][source.second]=0;
        
        vector<vector<int>> nrc={{-1,0},{0,1},{1,0},{0,-1}};
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{source.first,source.second}});
        
        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int newrow=row+nrc[i][0];
                int newcol=col+nrc[i][1];
                
                if(newrow==destination.first && newcol==destination.second) return dis+1;
                
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]==1 && dis+1<dist[newrow][newcol]){
                    q.push({dis+1,{newrow,newcol}});
                    dist[newrow][newcol]=dis+1;
                }
            }
        }
        if(dist[destination.first][destination.second]==INT_MAX)    return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends