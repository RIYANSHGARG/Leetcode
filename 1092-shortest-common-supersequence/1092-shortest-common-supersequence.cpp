class Solution {
public:
    int LCS(string &s1,string &s2, int i,int j, vector<vector<int>> &dp){
        if(i==0 || j==0)    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        
        if(s1[i-1]==s2[j-1])    return dp[i][j]=1+LCS(s1,s2,i-1,j-1,dp);
        return dp[i][j]=max(LCS(s1,s2,i-1,j,dp),LCS(s1,s2,i,j-1,dp));
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length(),m=str2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        int ans = n+m-LCS(str1,str2,n,m,dp);
        // for(auto i:dp){for(auto j:i){cout<<j<<" ";}cout<<endl;}
        string res="";
        int i=n,j=m;
        while(i>0 && j>0){
                if(str1[i-1]==str2[j-1])    {res+=str1[i-1];i--;j--;}
                else{
                    if(dp[i-1][j] > dp[i][j-1]) {res+=str1[i-1];i--;}
                    else    {res+=str2[j-1];j--;}
                }
        }
        while(i>0)  {res+=str1[i-1];i--;}
        while(j>0)  {res+=str2[j-1];j--;}
        reverse(res.begin(),res.end());
        return res;
    }
};