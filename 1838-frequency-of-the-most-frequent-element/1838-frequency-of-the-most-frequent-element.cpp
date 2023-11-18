class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // int freq=1;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-1;i++){
        //     long long int temp=0,noInc = 0,strt=nums[i];
        //     for(int j=i+1;j<nums.size();j++){
        //         long long int sum = (nums[j]-strt)*static_cast<long>(j-i);
        //         if(noInc+sum > k){
        //             break;
        //         }
        //         noInc+= sum;
        //         strt = nums[j];
        //         freq = max(freq,j-i+1);
        //     }
        // }
        // return freq;
        
        
        sort(nums.begin(), nums.end());

        int left=0,right =0;
        long res=0,total = 0;

        while(right < nums.size())
        {
            total += nums[right];

            while(nums[right]*static_cast<long>(right-left+1) > total+k)
            {
                total -= nums[left];
                left++;
            }
            res = max(res,static_cast<long>(right-left+1));
            right ++;
        }
        return res;
    }
};