class Solution {
public:
    
    int rec(int i, int buy ,int fee, vector<int> &prices , vector<vector<int>> &dp){
        if(i>=prices.size())    return 0;
        
        if(dp[i][buy]!=-1)  return dp[i][buy];
        
        int pick=INT_MIN,notPick=INT_MIN,profit;
        if(buy){
            pick=-prices[i]+rec(i+1,0,fee,prices,dp);
            notPick=rec(i+1,1,fee,prices,dp);
            profit = max(pick,notPick);
        }else{
            pick = prices[i] + rec(i+1,1,fee,prices,dp)-fee;
            notPick = rec(i+1,0,fee,prices,dp);
            profit = max(pick,notPick);
        }
        return dp[i][buy]=profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int> (2,-1));
        return rec(0,1,fee,prices,dp);
    }
};