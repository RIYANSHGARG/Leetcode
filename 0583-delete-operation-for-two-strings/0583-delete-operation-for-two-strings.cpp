class Solution {
public:
    int LCS(string &s1, string &s2, int i,int j, vector<vector<int>> &dp){
        if(i==0 || j==0)    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        
        if(s1[i-1]==s2[j-1])    return dp[i][j]=1+LCS(s1,s2,i-1,j-1,dp);
        return dp[i][j]=max(LCS(s1,s2,i-1,j,dp),LCS(s1,s2,i,j-1,dp));
    }
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return word1.length()+word2.length()-2*LCS(word1,word2,n,m,dp);
    }
};