class Solution {
public:
    
    bool rec(int i,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(target==0)   return true;
        if(i<0 || target<0) return false;
        
        if(dp[i][target]!=-1)   return dp[i][target];
        
        bool pick = rec(i-1,target-nums[i],nums,dp);
        bool notPick = rec(i-1,target,nums,dp);
        
        return dp[i][target]=pick || notPick;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0)    return false;
        
        vector<vector<int>> dp(nums.size(),vector<int> (sum,-1));
        return rec(nums.size()-1,sum/2,nums,dp);
    }
};