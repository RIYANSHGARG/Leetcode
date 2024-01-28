class Solution {
public:
    
//          DO AGAIN GOOD QUESTION
    
    
    int subArraySum(vector<int> &nums, int target){
        unordered_map<int,int> m;
        m[0]=1;
        int preSum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            cnt+=m[preSum-target];
            m[preSum]+=1;
        }
        return cnt;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int count=0;
        for(int i=0;i<matrix.size();i++){
            
            vector<int> sum(matrix[0].size(),0);
            for(int j=i;j<matrix.size();j++){
                for(int k=0;k<matrix[0].size();k++){
                    sum[k]+=matrix[j][k];
                }
                count+=subArraySum(sum,target);
            }
        }
        return count;
    }
};