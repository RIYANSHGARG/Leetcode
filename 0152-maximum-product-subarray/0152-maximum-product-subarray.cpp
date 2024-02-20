class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        // if(nums.size()==1)  return nums[0];
        // int neg=1,pos=1,var=1,hasZero=0;
        // for(int i=0;i<nums.size();i++){
        //     if(!nums[i])    {hasZero=1;var=1;continue;}
        //     var*=nums[i];
        //     neg=min(neg,var);
        //     pos=max(pos,var);
        // }
        // if(pos==1 && hasZero)  return *max_element(nums.begin(),nums.end());
        // return pos;
        
        // Method 1 : finding all the subarrays
        
        // Method 2 : Most intuitive mannar
        // if all are positive : product all
        // if even negative : product all
        // if odd negative : then prefix of that negative and sufix of that negative might be ans
        // if any 0 inbetween then new Array started.
//         int ans=INT_MIN;
//         int prefix=1,sufix=1;
//         for(int i=0;i<nums.size();i++){
//             prefix*=nums[i];
//             sufix*=nums[nums.size()-i-1];
            
//             ans=max(ans,max(prefix,sufix));
            
//             if(prefix==0)   prefix=1;
//             if(sufix==0)   sufix=1;
//         }
//         return ans;
        
        int maxi=INT_MIN;
        int ans=1;
        for(int i=0;i<nums.size();i++){
            ans*=nums[i];
            maxi = max(ans,maxi);
            if(ans==0)  ans=1;
        }
        ans=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans*=nums[i];
            maxi = max(ans,maxi);
            if(ans==0)  ans=1;
            
        }
        return maxi;
    }
};