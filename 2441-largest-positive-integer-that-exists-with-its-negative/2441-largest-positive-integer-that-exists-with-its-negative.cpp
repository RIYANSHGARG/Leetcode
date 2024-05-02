class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi=INT_MIN;
        set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.find(-(nums[i]))!=s.end()){
                maxi=max(maxi,abs(nums[i]));
            }
            s.insert(nums[i]);
        }
        return (maxi==INT_MIN)?-1:maxi;
    }
};