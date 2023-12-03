class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int ans = nums[(low+high)/2];
        while(low<=high){
            int mid = low+(high-low)/2;
            
            if(nums[low]==nums[mid] && nums[mid] == nums[high] && low!=mid && mid!=high){
                low++;
                high--;
                continue;
            }
            
            if(nums[low] <= nums[mid]){
                ans = min (ans , nums[low]);
                low=mid+1;
            }else{
                ans = min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};