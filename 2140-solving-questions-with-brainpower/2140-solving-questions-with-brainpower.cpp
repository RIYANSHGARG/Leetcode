class Solution {
public:
    
    long long rec(int i, vector<vector<int>> &arr,vector<long long> &dp){
        if(i>=arr.size()) return 0;
        if(dp[i]!=-1)   return dp[i];
        long long pick=arr[i][0];
        if(i+arr[i][1]+1<arr.size())    pick+=rec(i+arr[i][1]+1,arr,dp);
        long long notPick = rec(i+1,arr,dp);
        
        return dp[i]=max(pick,notPick);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),-1);
        return rec(0 , questions,dp);
    }
};