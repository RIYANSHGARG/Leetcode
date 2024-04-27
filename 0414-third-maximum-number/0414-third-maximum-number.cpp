class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()==1)  return nums[0];
        if(nums.size()==2)  return max(nums[0],nums[1]);
        
        priority_queue<int,vector<int>,greater<int>> pq;
        set<int> s;
        
        for(auto i:nums){
            if(s.find(i)!=s.end()){
                continue;
            }
            pq.push(i);
            s.insert(i);
            
            if(pq.size()>3){
                s.erase(pq.top());
                pq.pop();
            }
        }
        if(pq.size()<3) return *max_element(nums.begin(),nums.end());
        return pq.top();
    }
};