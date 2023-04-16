class Solution {
public:
    
//     void bfs(int i,int j,vector<vector<int>> &grid , int delrow[] ,int delcol[], int &count){
//         grid[i][j]=2;
//         queue<pair<int,int>> q;
//         q.push({i,j});
        
//         while(!q.empty()){
//             int row=q.front().first;
//             int col=q.front().second;
//             q.pop();
//             cout<<row<<" "<<col<<endl;
            
            
//             for(int k=0;k<4;k++){
//                 int newrow = row+delrow[k];
//                 int newcol = col+delcol[k];
                
//                 if(newrow >=0 && newrow<grid.size() && newcol>=0 && newcol<grid[0].size() && grid[newrow][newcol]!=0 && grid[newrow][newcol]!=2){
//                     count++;
//                     grid[newrow][newcol]=2;
//                     q.push({newrow,newcol});
//                 }
//             }
//         }
        
//     }
    int ans=0;
    
    void BFS(vector<vector<int>> &grid , int delrow[] ,int delcol[], int &count, queue<pair<pair<int,int>,int>> &q){
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int m=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int newrow=row+delrow[i];
                int newcol=col+delcol[i];
                
                if(newrow >=0 && newrow<grid.size() && newcol>=0 && newcol<grid[0].size() && grid[newrow][newcol]!=0 && grid[newrow][newcol]!=2){
                    grid[newrow][newcol]=2;
                    q.push({{newrow,newcol},m+1});
                    ans=m+1;
                }
                
            }
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0,n=grid.size(),m=grid[0].size();
        // vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        int delrow[4]={-1,0,0,1};
        int delcol[4]={0,-1,1,0};
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)   q.push({{i,j},0});
            }
        }
        BFS(grid, delrow,delcol, count,q);
        for(auto i:grid){
            for(auto j:i){
                if(j==1)    return -1;
            }
        }
        return ans;
    }
};