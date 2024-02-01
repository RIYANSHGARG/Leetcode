class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        
        for(int i=0;i<nums.size();i+=3){
            if(nums[i+2]-nums[i] > k)   return {};
        }
        vector<int> temp(3,-1);
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            temp[i%3]=nums[i];
            if(i%3==2)  ans.push_back(temp);
        }
        return ans;
    }
};
