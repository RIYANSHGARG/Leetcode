class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int flag=0;
        int product=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)  {flag++;continue;}
            else    product*=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(flag==0) nums[i]=product/nums[i];
            else if(flag==1){
                if(nums[i]==0) nums[i]=product;
                else    nums[i]=0;
            }
            else    nums[i]=0;
        }
        return nums;
    }
};