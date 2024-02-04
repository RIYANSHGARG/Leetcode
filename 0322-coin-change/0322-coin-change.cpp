class Solution {
    
public:
    long long rec(int i, int amount , vector<int> &coins,vector<vector<long long>> &dp){
        if(amount==0)   return 0;
        if(i<0 || amount<0) return INT_MAX;
        
        if(dp[i][amount]!=-1)   return dp[i][amount];
        
        long long notPick = rec(i-1,amount,coins,dp);
        long long pick = 1+rec(i,amount-coins[i],coins,dp);
        
        return dp[i][amount] = min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<long long>> dp(coins.size()+1 , vector<long long>(amount+1,-1));
        long long ans = rec(coins.size()-1 , amount , coins,dp);
        return (ans<INT_MAX)?ans:-1;
    }
};