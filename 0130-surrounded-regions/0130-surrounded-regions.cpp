class Solution {
public:
    void dfs(int row,int col, vector<vector<char>> &board, vector<vector<int>> &vis, vector<vector<int>> nrc){
        int n=board.size(),m=board[0].size();
        vis[row][col]=1;
        
        for(int i=0;i<4;i++){
            int newrow=row+nrc[i][0];
            int newcol=col+nrc[i][1];
            
            if(newrow>=0 && newrow<board.size()&& newcol>=0 && newcol<board[0].size() && board[newrow][newcol]=='O' && vis[newrow][newcol]==false){
                dfs(newrow,newcol,board,vis,nrc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> nrc={{-1,0},{0,-1},{0,1},{1,0}};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && board[i][j] == 'O'){
                    dfs(i,j,board,vis,nrc);
                }
            }
        }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O' && vis[i][j]==0)    board[i][j]='X';
            }
        }
    }
};