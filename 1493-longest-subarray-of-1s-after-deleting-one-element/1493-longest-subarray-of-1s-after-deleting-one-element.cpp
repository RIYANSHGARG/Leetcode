class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cz=0,i=0,j=0,ans=0;
        bool isz=false;
        while(j<nums.size()){
            if(!nums[j]){
                isz=true;
                cz++;
            }
            while(cz>1){
                if(!nums[i])  cz--;
                i++;
            }
            if(isz) ans=max(ans,j-i);
            else    ans=max(ans,j-i+1);
            j++;
            // cout<<ans;
        }
        return (!isz)?ans-1:ans;
    }
};