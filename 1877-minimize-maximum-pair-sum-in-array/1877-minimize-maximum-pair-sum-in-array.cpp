class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=n-1,ans=INT_MIN;
        while(i<j){
            if(nums[i]+nums[j] > ans)   ans=nums[i]+nums[j];
            i++;j--;
        }
        return ans;
    }
};