class Solution {
public:
    
    void sorting(vector<int> &nums){
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size()-i-1;j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j],nums[j+1]);
                }
            }
        }
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> extra = nums;
        sorting(nums);
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]==target) break;
            else if(nums[i]+nums[j]<target) i+=1;
            else j-=1;
        }
        vector<int> ans;
        for(int k=0;k<nums.size();k++){
            if(extra[k]==nums[i])    {ans.push_back(k);break;}
        }
        for(int k=0;k<nums.size();k++){
            if(extra[k]==nums[j] && k!=ans[0])    {ans.push_back(k);break;}
        }
        return ans;
    }
};