class Solution {
public:
    
    int rec(int i1,int i2,string &s1,string &s2,vector<vector<int>> &dp){
        if(i1==0)   return i2;
        if(i2==0)   return i1;
        
        if(dp[i1][i2]!=-1)  return dp[i1][i2];
        
        if(s1[i1-1]==s2[i2-1])  return dp[i1][i2]=rec(i1-1,i2-1,s1,s2,dp);
        else{
            int ins=rec(i1,i2-1,s1,s2,dp);
            int Del=rec(i1-1,i2,s1,s2,dp) ;
            int replace = rec(i1-1,i2-1,s1,s2,dp);
            return dp[i1][i2]=1+min(ins,min(Del,replace));
        }
        
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1 , vector<int>(word2.length()+1,-1));
        return rec(word1.length(),word2.length(),word1,word2,dp);
    }
};