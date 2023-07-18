//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int LCS(string &s1, string &s2, int i,int j, vector<vector<int>> &dp){
        if(i==0 || j==0)    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        
        if(s1[i-1]==s2[j-1])    return dp[i][j]=1+LCS(s1,s2,i-1,j-1,dp);
        return dp[i][j]=max(LCS(s1,s2,i-1,j,dp),LCS(s1,s2,i,j-1,dp));
    }
	int minOperations(string str1, string str2) 
	{ 
	    int n=str1.length(),m=str2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return str1.length()+str2.length()-2*LCS(str1,str2,n,m,dp);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends