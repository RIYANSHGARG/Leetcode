class Solution {
public:
    
    int rec(int i, vector<int> &nums,vector<int> &dp){
        if(i==nums.size()-1)  return dp[i]=nums[i];
        if(i>=nums.size())   return 0;
        
        if(dp[i]!=-1)   return dp[i];
        
        int firstHouse = 0+rec(i+1,nums,dp);
        int secondHouse = nums[i]+rec(i+2,nums,dp);
        // cout<<firstHouse<<" "<<secondHouse<<endl;
        return dp[i]=max(firstHouse,secondHouse);
    }
    
    int rob(vector<int>& nums) {
        int ans=0;
        vector<int> dp(nums.size(),-1);
        ans = rec(0,nums,dp);
        return ans;
    }
};