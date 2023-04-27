class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=0,profit=0,mj=0; 
    
        for( int i=1;i<prices.size();i++)
        {
            if(prices[i] <= prices[mn]) mn=i;
            else
            {
               profit = prices[i]-prices[mn] ; 
               mj += profit ; 
               mn = i ;  
            }
        }
        return mj ; 
    }
};