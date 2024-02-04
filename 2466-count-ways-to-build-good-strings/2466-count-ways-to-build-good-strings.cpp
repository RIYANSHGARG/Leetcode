int mod = (int)1e9+7;

class Solution {
public:
    
    int rec(int len , int zero , int one , int low , int high,vector<int> &dp){
        if(len>high)    return 0;
        if(dp[len]!=-1) return dp[len];
        int count=0;
        if(len>=low &&len<=high)    count=1;
        count+=rec(len+zero,zero,one,low,high,dp)%mod;
        count+=rec(len+one,zero,one,low,high,dp)%mod;
        return dp[len]=(count)%mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        return rec(0, zero , one , low , high,dp);
    }
};