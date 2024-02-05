class Solution {
public:
    int rec(int i1,int i2, string &s1,string &s2,vector<vector<int>> &dp){
        if(i1<0 || i2<0)    return 0;
        if(dp[i1][i2]!=-1)  return dp[i1][i2];
        if(s1[i1]==s2[i2])  return dp[i1][i2]=1+rec(i1-1,i2-1,s1,s2,dp);
        return dp[i1][i2]=max(rec(i1-1,i2,s1,s2,dp),rec(i1,i2-1,s1,s2,dp));
    }
    int minInsertions(string s) {
        string temp=s;
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(s.length(),vector<int> (s.length(),-1)); 
        
        int ans = rec(s.length()-1,s.length()-1,temp,s,dp);
        return s.length()-ans;
    }
};