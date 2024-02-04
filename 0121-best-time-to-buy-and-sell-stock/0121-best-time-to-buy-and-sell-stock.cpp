class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1)  return 0;
        // int i=0,small=prices[0],diff=INT_MIN;
        // stack<int> st;
        // while(i<prices.size()){
        //     if(st.empty()){
        //         st.push(prices[i]);
        //         i++;
        //         continue;
        //     }
        //     if(prices[i] < st.top()){
        //         while(!st.empty() && prices[i]<st.top())    st.pop();
        //         st.push(prices[i]);
        //         small=min(small,prices[i]);
        //     }else{
        //         st.push(prices[i]);
        //         diff = max(diff, abs(st.top()-small) );
        //     }
        //     i++;
        // }
        // return diff==INT_MIN ? 0:diff;
        
        int profit=0,min=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min){
                min=prices[i];
            }
            if(prices[i]-min > profit){
                profit=prices[i]-min;
            }
        }
        return profit;
    }
};