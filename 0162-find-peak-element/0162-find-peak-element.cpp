class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int prev=INT_MIN,i=0;
        for(i;i<nums.size()-1;i++){
            if(nums[i] > prev && nums[i]>nums[i+1]) return i;
            prev=nums[i];
        }
        return (nums[i] > prev && nums[i]>INT_MIN)? i:0;
    }
};