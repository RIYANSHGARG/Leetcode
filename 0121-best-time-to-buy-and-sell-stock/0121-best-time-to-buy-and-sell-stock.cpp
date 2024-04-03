class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1)    return 0;
        int ans=0,mini=prices[0];
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mini){
                mini=prices[i];
            }else{
                ans=max(ans,prices[i]-mini);
            }
        }
        return ans;
    }
};