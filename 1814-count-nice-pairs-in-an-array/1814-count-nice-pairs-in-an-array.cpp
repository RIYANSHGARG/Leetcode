class Solution {
public:
    int mod = 1e9+7;
    int rev(int num){
        int ans=0;
        while(num){
            ans=ans*10+num%10;
            num/=10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        
        // vector<long long int> revnum;
        // for(int i=0;i<nums.size();i++){
        //     revnum.push_back(rev(nums[i]));
        //     // cout<<revnum[i]<<" ";
        // }
        // long long int ans=0;
        // for(int i=0;i<nums.size()-1;i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if( (nums[i]-revnum[i])%mod == (nums[j]-revnum[j])%mod ){
        //             ans=(ans+1)%mod;
        //             continue;
        //         }
        //     }
        //     cout<<ans<<" ";
        // }
        // return (int)ans;
        
        int ans=0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            int temp = (nums[i]-rev(nums[i]));
            mp[temp]++;
            ans = (ans+mp[temp]-1)%mod;
        }
        return ans;
    }
};