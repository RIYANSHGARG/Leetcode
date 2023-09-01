class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f=INT_MAX,r=INT_MAX;
        if(nums.size()<3) return false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=f)    f=nums[i];
            else if(nums[i] > f && nums[i]<=r)   r=nums[i];
            else    return true;
        }
        return false;
    }
};