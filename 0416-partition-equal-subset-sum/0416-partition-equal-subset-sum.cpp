class Solution {
public:
    
    bool rec(int i, int target, vector<int> &nums,vector<vector<int>> &dp){
        if(target==0)   return true;
        if(i==0){
            return (nums[i]==target);
        }
        if(dp[i][target]!=-1)   return dp[i][target];
        bool notpick=rec(i-1,target,nums,dp);
        bool pick=false;
        if(target-nums[i]>=0)   pick=rec(i-1,target-nums[i],nums,dp);
        
        return dp[i][target]=notpick|pick;
    }
    
    bool canPartition(vector<int>& nums) {
        int totSum=0;
        for(auto &it:nums)  totSum+=it;
        if(totSum%2!=0) return false;
        // total sum/2 is out target sum that we need to find.
        vector<vector<int>> dp(nums.size(),vector<int>(totSum+1 ,-1));
        return rec(nums.size()-1,totSum/2,nums,dp);
    }
};