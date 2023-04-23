class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> ans;
        if(nums.size()==1)  return {0};
        int presum=0,postsum=0;
        for(int i=0;i<nums.size();i++)  postsum+=nums[i];
        for(int i=0;i<nums.size();i++){
            ans.push_back(abs(postsum-nums[i]-presum));
            presum+=nums[i];
            postsum-=nums[i];
        }
        return ans;
    }
};