class Solution {
public:
    int rec(int idx1,int idx2, string &s1,string &s2, vector<vector<int>> &dp){
        if(idx1<0 || idx2<0)    return 0;
        if(dp[idx1][idx2]!=-1)  return dp[idx1][idx2];
        if(s1[idx1]==s2[idx2])  return dp[idx1][idx2]=1+rec(idx1-1,idx2-1,s1,s2,dp);
        return dp[idx1][idx2]=0+max(rec(idx1-1,idx2,s1,s2,dp),rec(idx1,idx2-1,s1,s2,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(),vector<int> (text2.length(),-1));
        
        return rec(text1.length()-1,text2.length()-1,text1,text2,dp);
    }
};