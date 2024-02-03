class Solution {
public:
    
    int rec(int i, int m , int n, vector<string> &arr,vector<vector<vector<int>>> &dp){
        if(m<0 || n<0){
            return 0;
        }
        if(i==0){
            int numZero=0,numOne=0;
            for(int j=0;j<arr[i].length();j++){
                if(arr[i][j]=='0')  numZero++;
                else numOne++;
            }
            if(m-numZero>=0 && n-numOne>=0) return 1;
            else return 0;
        }
        
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        
        int numZero=0,numOne=0;
        for(int j=0;j<arr[i].length();j++){
            if(arr[i][j]=='0')  numZero++;
            else numOne++;
        }
        
        int pick=0;
        if(m-numZero>=0 && n-numOne>=0)    pick=1+rec(i-1,m-numZero,n-numOne,arr,dp);
        int notPick=rec(i-1,m,n,arr,dp);
        
        return dp[i][m][n]=max(pick,notPick);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>> (m+1,vector<int> (n+1,-1)));
        return rec(strs.size()-1,m,n,strs,dp);
    }
};