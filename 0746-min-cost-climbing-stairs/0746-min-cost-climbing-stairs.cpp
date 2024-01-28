class Solution {
public:
    
    int rec(int i, vector<int> &cost,vector<int> &dp){
        if(i>=cost.size()-1)  return 0;
        
        if(dp[i]!=-1)   return dp[i];
        
        int stepOne = cost[i]+rec(i+1,cost,dp);
        int stepTwo = cost[i+1]+rec(i+2,cost,dp);
        return dp[i]=min(stepOne,stepTwo);
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        int ans=0;
        
        vector<int> dp(cost.size(),-1);
        ans = rec(0,cost,dp);
        return ans;
    }
};