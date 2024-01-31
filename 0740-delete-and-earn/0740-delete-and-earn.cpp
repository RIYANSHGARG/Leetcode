class Solution {
public:
    int rec(int i,vector<int> &v,vector<int> &dp){
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1)   return dp[i];
        int ind=i,currentValue=v[i],currentSum=0;
        while(ind>=0 && v[ind]==currentValue){
            currentSum+=v[ind];
            ind--;
        }
        while(ind>=0 && v[ind]==currentValue-1){
            ind--;
        }
        
        return dp[i]=max(currentSum+rec(ind,v,dp) , rec(i-1,v,dp));
        
    }
    
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),-1);
        int ans=0;
        ans=rec(nums.size()-1,nums,dp);
        return ans;
    }
};