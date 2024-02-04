class Solution {
public:
    
    int rec(int i, int buy, int times , vector<int> &prices , vector<vector<vector<int>>> &dp){
        if(i>=prices.size() || times<=0)    return 0;
        
        if(dp[i][buy][times]!=-1)  return dp[i][buy][times];
        
        int pick=INT_MIN,notPick=INT_MIN,profit;
        if(buy){
            pick=-prices[i]+rec(i+1,0,times,prices,dp);
            notPick=rec(i+1,1,times,prices,dp);
            profit = max(pick,notPick);
        }else{
            pick = prices[i] + rec(i+1,1,times-1,prices,dp);
            notPick = rec(i+1,0,times,prices,dp);
            profit = max(pick,notPick);
        }
        return dp[i][buy][times]=profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (2,vector<int> (k+1,-1)));
        return rec(0,1,k,prices,dp);
    }
};