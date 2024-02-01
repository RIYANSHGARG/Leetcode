class Solution {
public:
    
    int rec(int i,int j, int n,vector<vector<int>> &triangle,vector<vector<int>> &dp){
        if(i==n)    return 0;
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int bottomLeft = triangle[i][j]+rec(i+1,j,n,triangle,dp);
        int bottomRight = triangle[i][j]+rec(i+1,j+1,n,triangle,dp);
        
        return dp[i][j]=min(bottomLeft,bottomRight);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        for(auto i:triangle){
            vector<int> temp;
            for(auto j:i){
                temp.push_back(-1);
            }
            dp.push_back(temp);
        }
        return rec(0,0,triangle.size(),triangle,dp);
    }
};