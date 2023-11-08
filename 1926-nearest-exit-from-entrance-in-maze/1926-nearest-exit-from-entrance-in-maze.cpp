class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
//         int ans=0;
        
//         int startx=entrance[0],starty=entrance[1];
        
//         queue<pair<pair<int,int>,int>> q;
//         q.push({{entrance[0],entrance[1]},0});
//         vector<vector<int>> vis(maze.size(),vector<int> (maze[0].size(),0));
        
//         vector<int> delrow = {-1,0,1,0};
//         vector<int> delcol = {0,1,0,-1};
        
//         while(!q.empty()){
//             int r=q.front().first.first;
//             int c=q.front().first.second;
//             int t=q.front().second;
//             vis[r][c]=1;
//             q.pop();
            
//             for(int i=0;i<4;i++){
//                 int newRow = r+delrow[i];
//                 int newCol = c+delcol[i];
                
//                 if(newRow<0 || newRow >=maze.size() || newCol <0 || newCol >=maze[0].size()){
//                     if(r==startx && c==starty)  continue;
//                     return t;
//                 }
                
//                 if(maze[newRow][newCol]=='.' && vis[newRow][newCol]!=1){
//                     q.push({{newRow,newCol},t+1});
//                 }
//             }
//         }
//         return -1;
        
        
        int m = maze.size();
    int n = maze[0].size();
    
    queue<pair<int, int>> q;
    q.push({entrance[0], entrance[1]});
    
    vector<vector<int>> dist(m, vector<int>(n, -1));
    dist[entrance[0]][entrance[1]] = 0;
    
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] == '.' && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
                
                // Check if the exit is on the border
                if (nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1) {
                    return dist[nr][nc];
                }
            }
        }
    }
    
    return -1;
    }
};