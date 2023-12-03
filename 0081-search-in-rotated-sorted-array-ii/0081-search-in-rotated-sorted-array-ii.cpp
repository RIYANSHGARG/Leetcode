class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // only case that is causing difficulty is
        // arr[low]==arr[mid]==arr[high]    after eliminating this case simple search in rotated sorted array 1 works
        
//         int low = 0,high=nums.size()-1;
//         while(low<=high){
//             int mid=low+(high-low)/2;
            
//             if(nums[mid]==target)   return true;
//             if(nums[low]==nums[mid] && nums[mid]==nums[high]){low++;high--;continue;}

//             if(nums[low] <= nums[mid]){
//                 if(target>=nums[low] && target <= nums[mid])    high=mid-1;
//                 else    low=mid+1;
//             }else{
//                 if(target >= nums[mid] && target <= nums[high])  low=mid+1;
//                 else    high=mid-1;
//             }
//         }
        
        
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target)   return true;
            
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){low++;high--;continue;}
            
            if(nums[mid] <= nums[high]){
                if(target <= nums[high] && target>=nums[mid]) low = mid+1;
                else high=mid-1;
            }else{
                if(target >= nums[low] && target <= nums[mid])  high=mid-1;
                else    low=mid+1;
            }
        }
        
        return false;
    }
};