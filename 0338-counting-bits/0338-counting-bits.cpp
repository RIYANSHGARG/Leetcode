class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        // Method 1
        // for(int i=0;i<=n;i++){
        //     ans.push_back(__builtin_popcount(i));
        // }
        // return ans;
        
        // Mehtod 2
        if(n==0)    return {0};
        if(n==1)    return {0,1};
        // ans[0]=0;ans[1]=1;//2^0
        // ans[2]=1;//2^1
        ans.push_back(0);
        ans.push_back(1);
        ans.push_back(1);
        int count=1;
        for(int i=3;i<=n;i++){
            if(i>=pow(2,count+1)){
                count++;
                ans.push_back(1);
            }
            else{
                ans.push_back(1+ans[i-pow(2,count)]);
            }
        }
        return ans;
    }
};