int rec(int i, int buy, int times , vector<int> &prices , vector<vector<vector<int>>> &dp){
if(i>=prices.size())    return 0;
if(times==0)    return 0;
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