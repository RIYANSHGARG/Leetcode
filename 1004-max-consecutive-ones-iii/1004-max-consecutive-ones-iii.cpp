class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi=0,i=0,j=0,cz=0;
        while(j<nums.size()){
            if(!nums[j]){
                cz++;
            }
            while(cz>k){
                if(nums[i]==0)  cz--;
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};