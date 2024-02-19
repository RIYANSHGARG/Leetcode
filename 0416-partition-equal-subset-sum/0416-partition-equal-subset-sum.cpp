class Solution {
public:
    
    bool rec(int i , vector<int> &nums , int tar , vector<vector<int>> &dp){
        if(tar==0)   return true;
        if(i==0)    return (tar==nums[i]);
        if(dp[i][tar]!=-1)   return dp[i][tar];
        
        // pick
        bool pick=false,notpick=false;
        if(tar-nums[i]>=0)   pick=rec(i-1,nums,tar-nums[i],dp);
        notpick=rec(i-1,nums,tar,dp);
        return dp[i][tar]=pick|notpick;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums)    sum+=i;
        if(sum&1)   return false;
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,-1));
        return rec(nums.size()-1 , nums , sum/2 , dp);
    }
};