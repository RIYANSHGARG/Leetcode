class Solution {
public:
    int LIS(vector<int> &v,int ind,int prev,vector<vector<int>> &dp){
        if(ind>=v.size())   return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int len=LIS(v,ind+1,prev,dp);
        if(prev==-1 || v[prev] < v[ind]){
            len=max(len,1+LIS(v,ind+1,ind,dp));
        }
        return dp[ind][prev+1]=len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // int ind=0,prev=-1,n=nums.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1) );
        // int ans=LIS(nums,ind,prev,dp);
        // for(auto i:dp){for(auto j:i){cout<<j<<" ";}cout<<endl;}
        // return ans;
        
        // -------------------- Binary Search-------------------
        
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i] > temp.back())   temp.push_back(nums[i]);
            else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return temp.size();
    }
};