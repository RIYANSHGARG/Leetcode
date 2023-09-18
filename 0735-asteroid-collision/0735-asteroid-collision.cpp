class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.empty() || nums[i]>0)  s.push(nums[i]);
            else{
                while(true){
                    if(s.top() < 0){s.push(nums[i]);break;}
                    else if(s.top() > (-1)*nums[i]){break;}
                    else if(s.top() == (-1)*nums[i] ){s.pop();break;}
                    else{
                        s.pop();
                        if(s.empty()){s.push(nums[i]); break;}
                    }
                }
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};