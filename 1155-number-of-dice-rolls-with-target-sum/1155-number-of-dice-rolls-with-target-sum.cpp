class Solution {
public:
//     int mod = 1e9+7;
//     void rec(long long sum, int n, int k, int &target, long long &count){
//         if(sum==target && n==0){
//             cout<<sum<<" ";
//             count=(count+1)%mod;
//             return;
//         }
//         long long currsum=0;
//         for(int i=1;i<=k;i++){
//             currsum=(sum%mod+i)%mod;
//             // cout<<currsum<<" ";
//             for(int i=0;i<n;i++){
//                 rec(currsum,n-1,k,target,count);
//             }
//         }
//     }
    
    
//     int dp[31][1001] = {};
//     int numRollsToTarget(int d, int f, int target, int res = 0) {
//       if (d == 0 || target <= 0) return d == target;
//       if (dp[d][target]) return dp[d][target] - 1;
//       for (auto i = 1; i <= f; ++i)
//         res = (res + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
//       dp[d][target] = res + 1;
//       return res;
//     }
    
    int numRollsToTarget(int d, int f, int target) {
        int m=1000000007;
        vector<vector<int> > dp(d+1, vector<int>(target+1, 0));
        dp[0][0]=1;
        for(int i=1; i<=d; i++){
            for(int j=1; j<=target; j++){
                for(int k=1; k<=f; k++){
                    if(k<=j)
                        dp[i][j]=((dp[i][j]%m)+(dp[i-1][j-k]%m))%m;
                }
            }
        }
        return dp[d][target];
    }
};