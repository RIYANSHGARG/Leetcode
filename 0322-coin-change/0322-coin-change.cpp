class Solution {
public:
    
    long long int rec(int i,int amount,vector<int> &amounts,vector<vector<int>> &dp){
        if(amount==0)   return 0;
        if(i<0 || amount<0) return INT_MAX;
        
        if(dp[i][amount]!=-1)   return dp[i][amount];
        
        long long int pick=1+rec(i,amount-amounts[i],amounts,dp);
        long long int notPick=rec(i-1,amount,amounts,dp);
        
        return dp[i][amount]=min(pick,notPick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        long long int ans = rec(coins.size()-1,amount,coins,dp);
        return (ans<INT_MAX)?ans:-1;
    }
};