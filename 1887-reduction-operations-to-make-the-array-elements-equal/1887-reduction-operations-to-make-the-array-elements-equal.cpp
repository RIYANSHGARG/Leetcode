class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int cnt = 0, prev = 0;
        sort(nums.begin(), nums.end());

        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]){
                prev +=1;
            }
            cnt += prev;
        }

        return cnt;
    }
};