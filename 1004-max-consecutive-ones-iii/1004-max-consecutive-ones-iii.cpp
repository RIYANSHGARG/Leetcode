class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,count=0,maxCount=0;
        while(r<nums.size()){
            count++;
            if(nums[r]==0)  k--;
            while(k<0){
                count--;
                if(nums[l]==0)  k++;
                l++;
            }
            if(k>=0)    maxCount=max(count,maxCount);
            r++;
        }
        return maxCount;
    }
};