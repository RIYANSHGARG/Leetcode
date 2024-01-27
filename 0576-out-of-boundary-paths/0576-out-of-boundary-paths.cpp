int mod=1e9+7;

class Solution {
public:
    
    void bfs(int &n, int &m, int maxMove , int sr, int sc, int &res){
        if(sr<0 || sc<0 || sr>=n || sc>=m || maxMove<0){
            if(maxMove>=0)  res=(res+1)%mod;
            return ;
        }
        
        bfs(n,m,maxMove-1,sr-1,sc,res);
        bfs(n,m,maxMove-1,sr,sc-1,res);
        bfs(n,m,maxMove-1,sr,sc+1,res);
        bfs(n,m,maxMove-1,sr+1,sc,res);
        
    }
    
    
     int bfs_memo(int &n, int &m, int maxMove , int sr, int sc, int &res, vector<vector<vector<int>>> &dp){
        if(sr<0 || sc<0 || sr>=n || sc>=m)  return 1;
        if(maxMove<=0)  return 0;

        if(dp[sr][sc][maxMove]!=-1){
            return dp[sr][sc][maxMove];
        }

        long long path=0;
             
         
        path=(path+bfs_memo(n,m,maxMove-1,sr-1,sc,res,dp))%mod;
        path=(path+bfs_memo(n,m,maxMove-1,sr,sc-1,res,dp))%mod;
        path=(path+bfs_memo(n,m,maxMove-1,sr,sc+1,res,dp))%mod;
        path=(path+bfs_memo(n,m,maxMove-1,sr+1,sc,res,dp))%mod;
        
        dp[sr][sc][maxMove]=path;
        return path;
    }
    
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int res=0;
        vector<vector<vector<int>>> dp(51,vector<vector<int>>(51,vector<int> (51,-1)));
        // bfs(m,n,maxMove,startRow,startColumn , res);
        res = bfs_memo(m,n,maxMove,startRow,startColumn , res, dp);
        return res;
    }
};