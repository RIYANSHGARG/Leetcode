int rec(int idx1,int idx2, string &s1,string &s2, vector<vector<int>> &dp){
if(idx1<0 || idx2<0)    return 0;
if(dp[idx1][idx2]!=-1)  return dp[idx1][idx2];
if(s1[idx1]==s2[idx2])  return dp[idx1][idx2]=1+rec(idx1-1,idx2-1,s1,s2,dp);
return dp[idx1][idx2]=0+max(rec(idx1-1,idx2,s1,s2,dp),rec(idx1,idx2-1,s1,s2,dp));
}
int longestCommonSubsequence(string text1, string text2) {
// vector<vector<int>> dp(text1.length(),vector<int> (text2.length(),-1));
// return rec(text1.length()-1,text2.length()-1,text1,text2,dp);
int n=text1.length(),m=text2.length();
vector<vector<int>> dp(n+1,vector<int> (m+1,0));
// for(int i=0;i<text1.length();i++)   dp[]
for(int i=1;i<n+1;i++){
for(int j=1;j<m+1;j++){
if(text1[i-1]==text2[j-1])  dp[i][j]=1+dp[i-1][j-1];
else    dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
}
}
// return dp[n][m];
// Printing LCS : Traversing dp matrix in reverse to get elements.
string ans;
int i=n,j=m;
while(i>0 && j >0){
if(text1[i-1] == text2[j-1])    {ans+=text1[i-1];i--;j--;}
else{
if(dp[i-1][j] > dp[i][j-1]){
i--;
}else{j--;}
}
}
reverse(ans.begin(),ans.end());
cout<<ans;
return dp[n][m];
}