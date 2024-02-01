class Solution {
public:
    int rec(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(grid[i][j]==1)   return 0;
        if(i==0 && j==0)    return dp[i][j]=1;
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int left=rec(i,j-1,grid,dp);
        int up=rec(i-1,j,grid,dp);
        
        return dp[i][j]=left+up;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ans=0,n=obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        ans=rec(n-1,m-1,obstacleGrid,dp);
        return ans;
    }
};