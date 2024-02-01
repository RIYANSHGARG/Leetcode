class Solution {
public:
    
    int rec(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i<0 || j<0) return INT_MAX;
        if(i==0 && j==0)    return dp[i][j]=grid[i][j];
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int left=rec(i,j-1,grid,dp);
        int up=rec(i-1,j,grid,dp);
        
        return dp[i][j]=grid[i][j]+min(left,up);
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int ans=0,n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        ans=rec(n-1,m-1,grid,dp);
        return ans;
    }
};