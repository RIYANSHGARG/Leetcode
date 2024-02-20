class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
//          Very good question
        // 3+3
        //   6 is preSum
        //   6-3 = 3 and it occurs twice hence we add 2 in cnt
        
        // unordered_map<int,int> m;
        // int cnt=0,preSum=0;
        // m[0]=1;
        // for(int i=0;i<nums.size();i++){
        //     preSum+=nums[i];
        //     cnt+=m[preSum-k];
        //     m[preSum]+=1;
        // }
        // return cnt;
        
        int sum=0;
        vector<int> preSum;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            preSum.push_back(sum);
        }
        unordered_map<int,int> m;
        int ans=0,pre;
        for(int i=0;i<nums.size();i++){
            pre+=nums[i];
            if(pre==k)    ans++;
            if(m.find(pre-k)!=m.end()){
                ans+=m[pre-k];
            }
            m[pre]++;
        }
        return ans;
    }
};