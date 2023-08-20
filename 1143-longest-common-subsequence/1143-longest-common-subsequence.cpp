class Solution {
public:
    
    int rec(string &s1,int i1, string &s2, int i2,  vector<vector<int>> &dp){
        if(i1<0 || i2<0)    return 0;
        if(dp[i1][i2]!=-1)  return dp[i1][i2];
        if(s1[i1] == s2[i2])    return dp[i1][i2] = 1+rec(s1,i1-1,s2,i2-1,dp);
        return dp[i1][i2] = max(rec(s1,i1-1,s2,i2,dp),rec(s1,i1,s2,i2-1,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.length(),vector<int> (text2.length(),-1));
        int ans=rec(text1,text1.length()-1, text2, text2.length()-1,dp);
        return ans;
    }
};