class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int first=prices[0],second=INT_MAX;
        for(int i=1;i<prices.size();i++){
            if(prices[i] < first){
                second = first;
                first = prices[i];
            }else if(prices[i] >= first && prices[i] < second){
                second = prices[i];
            }
        }
        int leftover = money-(first+second);
        return (leftover < 0)? money : leftover;
    }
};