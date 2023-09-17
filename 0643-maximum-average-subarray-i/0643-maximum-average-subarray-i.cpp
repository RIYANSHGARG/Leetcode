class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        ans=(double)sum/k;
        if(nums.size()==k)  return ans;
        
        for(int i=1;i<nums.size()-k+1;i++){
            sum-=nums[i-1];
            sum+=nums[i+k-1];
            double avg = (double)sum/k;
            ans=max(ans,avg);
        }
        return ans;
    }
};