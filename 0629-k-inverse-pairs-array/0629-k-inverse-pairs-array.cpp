class Solution {
public:
    int mod=1e9+7;
    
    int kInversePairs(int n, int k) {
        if(k==0)    return 1;   
        vector<vector<int>> dp(1001,vector<int> (1001,0));
        dp[0][0]=1;
        
        for(int i=1;i<=1000;i++){
            long long int val = 0;
            for(int j=0;j<=1000;j++){
                val=(val+dp[i-1][j]);
                if(j>=i){
                    val= (val - dp[i-1][j-i]);
                }
                dp[i][j]=val%mod;
            }
        }
        
        return dp[n][k];
    }
};
