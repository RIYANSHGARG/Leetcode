class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        // Main logic happen when it Get sorted as whe got sorted all the elements before it will be divisible. so just need to check the last element.
        // to get the array create a hash array contains the 
        sort(nums.begin(),nums.end());
        int ans=0;
        vector<int> index(nums.size(),1),hash(nums.size());
        for(int i=0;i<nums.size();i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[j] % nums[i]==0 || nums[i] % nums[j]==0){
                    if(1+index[j] > index[i]){
                        index[i]=1+index[j];
                        hash[i]=j;
                    }
                }
            }
        }
        int maxi=*max_element(index.begin(),index.end());
        ans=find(index.begin(),index.end(),maxi)-index.begin();
        
        cout<<ans<<endl;
        for(auto i:index)    cout<<i<<" ";
        cout<<endl;
        for(auto i:hash)    cout<<i<<" ";
        cout<<endl;
        
        vector<int> res;
        while(hash[ans]!=ans){
            res.push_back(nums[ans]);
            ans=hash[ans];
        }
        res.push_back(nums[ans]);
        reverse(res.begin(),res.end());
        return res;
    }
};