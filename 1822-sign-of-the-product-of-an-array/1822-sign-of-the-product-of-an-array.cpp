class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg=0,pos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)  return 0;
            else if(nums[i]>0)  pos++;
            else    neg++;
        }
        if(neg%2==0)    return 1;
        else    return -1;
    }
};