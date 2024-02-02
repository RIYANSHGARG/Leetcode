class Solution {
public:
    
    int rec(int i,vector<int> &dp){
        if(i==0)    return dp[i]=1;
        if(i<0) return 0;
        if(dp[i]!=-1)   return dp[i];
        int pick=rec(i-2,dp);
        int notpick=rec(i-1,dp);
        
        return dp[i]=pick+notpick;
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return rec(n,dp);
    }
};