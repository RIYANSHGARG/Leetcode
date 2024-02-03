class Solution {
public:
    
    int rec(int ind, int tar, vector<int> &arr,vector<vector<int>> &dp){
        if(tar==0)  return 0;
        if(ind==0){
            return tar/arr[ind];
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        int notPick = rec(ind-1,tar,arr,dp);
        int pick = INT_MAX;
        if(tar-arr[ind]>=0)    pick=1+rec(ind,tar-arr[ind],arr,dp);
        
        return dp[ind][tar]=min(pick,notPick);
    }
    
    
    int numSquares(int n) {
        vector<int> sum(sqrt(n)+1,0);
        int sz=sum.size();
        for(int i=1;i<=sz;i++){
            sum[i-1]=i*i;
        }
        vector<vector<int>> dp(sz,vector<int> (n+1,-1));
        return rec(sz-1,n,sum,dp);
    }
};