class Solution {
public:
    int rec(int i, vector<int> &prices, int buy,vector<vector<vector<int>>> &dp,int count){
        if(count>=2) return 0;
        if(i>=prices.size())    return 0;
        
        if(dp[i][buy][count]!=-1)  return dp[i][buy][count];
        
        int pick=INT_MIN,notPick=INT_MIN,profit=0;
        if(buy==0){
            pick=-prices[i]+rec(i+1,prices,1,dp,count);
            notPick=rec(i+1,prices,0,dp,count);
            profit=max(pick,notPick);
        }else{
            pick=prices[i]+rec(i+1,prices,0,dp,count+1);
            notPick = rec(i+1,prices,1,dp,count);
            profit=max(pick,notPick);
        }
        return dp[i][buy][count]=profit;
        
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (2,vector<int> (2,-1)));
        int ans = rec(0,prices,0,dp,0);
        return ans;
    }
};