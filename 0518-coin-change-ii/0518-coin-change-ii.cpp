class Solution {
public:
    
    int rec(int i, int amount , vector<int> &coins,vector<vector<int>> &dp){
        if(amount==0)   return 1;
        if(i==0){
            if(amount%coins[i]==0)    return 1;
            else    return 0;
        }
        
        if(dp[i][amount]!=-1)   return dp[i][amount];
        
        int notPick = rec(i-1,amount,coins,dp);
        int pick = 0;
        if(amount-coins[i]>=0)    pick=rec(i,amount-coins[i],coins,dp);
        
        return dp[i][amount] = pick+notPick;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() , vector<int>(amount+1,-1));
        return rec(coins.size()-1 , amount , coins,dp);
    }
};