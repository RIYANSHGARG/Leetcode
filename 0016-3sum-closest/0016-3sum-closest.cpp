class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()==3)  return nums[0]+nums[1]+nums[2];
        
        int ans=0,nearest=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum == target)   return target;
                
                if(abs(target-sum) < nearest){
                    ans=sum;
                    nearest=abs(target-sum);
                }
                
                if(sum>target)  k--;
                else    j++;
            }
        }
        return ans;
    }
};