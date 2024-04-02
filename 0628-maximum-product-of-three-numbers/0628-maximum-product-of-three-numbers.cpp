class Solution {
public:
    void sorting(vector<int> &nums){
        for(int i=0;i<nums.size()-1;i++){
            int j=0;
            while(j<nums.size()-i-1){
                if(nums[j]>nums[j+1]){
                    swap(nums[j],nums[j+1]);
                }    
                j++;
            }
        }
    }
    int maximumProduct(vector<int>& nums) {
        sorting(nums);
        for(auto num:nums){
            cout<<num<<" ";
        }
        return max(nums[0]*nums[1]*nums[nums.size()-1],
                   nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3]);
    }
};