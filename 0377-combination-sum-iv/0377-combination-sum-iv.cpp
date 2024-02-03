class Solution {
public:
    int rec( int amount , vector<int> &coins,vector<int> &dp){
        if(amount==0)   return 1;
        
        if(dp[amount]!=-1)   return dp[amount];
        
        int sum=0;
        for(auto ind:coins){
            if(amount-ind>=0)    sum+=rec(amount-ind,coins,dp);
        }
        return dp[amount]=sum;
    }
    int combinationSum4(vector<int>& nums, int target) {
         vector<int> dp(target+1,-1);
        return rec(target , nums, dp);
    }
};