class Solution {
public:
    int rec(int i, int j, vector<vector<int>> &matrix,vector<vector<int>> &dp){
        if(j<0 || j>=matrix[0].size())  return INT_MAX;
        if(i==matrix.size()-1)  return dp[i][j]=matrix[i][j];
        if(dp[i][j]!=INT_MAX)    return dp[i][j];
        
        
        int sum=INT_MAX;
        for(int k=-1;k<=1;k++){
            sum=min(sum,rec(i+1,j+k,matrix,dp));
        }
        return dp[i][j]=sum+matrix[i][j];
    }
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,INT_MAX) );
        for(int i=0;i<matrix.size();i++){
            ans=min(ans,rec(0,i,matrix,dp));
        }
        return ans;
    }
};