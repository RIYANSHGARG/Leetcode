int mod = (int)2*1e9;

class Solution {
public:
    
    int rec(int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0)  return 0;
        if(i==0 && j==0) return dp[i][j]=1%mod;
         
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = rec(i,j-1,dp)%mod;
        int up = rec(i-1,j,dp)%mod;
        
        return dp[i][j]=(left%mod+up%mod)%mod;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        // return rec(m-1,n-1,dp);
        dp[0][0]=1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)  continue;
                int left=0,right=0;
                if(i>0)  left=dp[i-1][j]%mod;
                if(j>0)  right=dp[i][j-1]%mod ;
                dp[i][j]=(left+right)%mod;
            }
        }
        
        
        
        
        return dp[m-1][n-1];
        
        
    }
};