class Solution {
public:
    
    int rec(int i,int k,vector<int> &arr,vector<int> &dp){
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1)   return dp[i];
        int curmax=0;
        int sum=0;
        
        for(int j=0;j<k;j++){
            if(i-j<0)   break;
            curmax=max(curmax,arr[i-j]);
            sum=max(sum,curmax*(j+1) + rec(i-j-1,k,arr,dp));
        }
        
        return dp[i]=sum;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return rec(arr.size()-1 , k, arr,dp);
    }
};