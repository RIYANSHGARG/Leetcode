class Solution {
public:
    int LCS(string &s1, string &s2, int ind1, int ind2 , vector<vector<int>> dp){
        if(ind1==0 || ind2==0)    return 0;
        
        if(dp[ind1][ind2]!=-1)  return dp[ind1][ind2];
        
        if(s1[ind1-1]==s2[ind2-1])  return dp[ind1][ind2]=1+(LCS(s1,s2,ind1-1,ind2-1,dp));
        else{
            return dp[ind1][ind2]=max(LCS(s1,s2,ind1-1,ind2,dp),LCS(s1,s2,ind1,ind2-1,dp));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        string rev=s;
        reverse(s.begin(),s.end());
        swap(s,rev);
        // vector<vector<int>> dp(s.length()+1,vector<int> (s.length()+1,-1));
        // return LCS(s,rev , s.length(), s.length(), dp);
        
        vector<vector<int>> dp(s.length()+1,vector<int> (s.length()+1,0));
        
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=s.length();j++){
                if(s[i-1]==rev[j-1])  dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[s.length()][s.length()];
    }
};