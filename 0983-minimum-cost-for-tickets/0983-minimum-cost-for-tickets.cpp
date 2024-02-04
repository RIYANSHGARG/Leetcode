class Solution {
public:
    
    int rec(int i, vector<int> &days , vector<int> &cost,vector<int> &dp ){
        if(i>=days.size()){
            return 0;
        }
        if(dp[i]!=-1)   return dp[i];
        int curday = days[i];
        int minCost=INT_MAX;
        for(int j=0;j<3;j++){
            int value=cost[j];
            
            int nextDay=i;
            if(j==0){
                while(nextDay<days.size() && days[nextDay] < days[i]+1)   nextDay++;
                value+= rec(nextDay,days,cost,dp);
            }else if(j==1){
                while(nextDay<days.size() && days[nextDay] < days[i]+7)   nextDay++;
                value+= rec(nextDay,days,cost,dp);
            }else{
                while(nextDay<days.size() && days[nextDay] < days[i]+30)   nextDay++;
                value+= rec(nextDay,days,cost,dp);
            }
            minCost=min(minCost , value);
        }
        return dp[i]=minCost;
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(),-1);
        return rec(0,days,costs,dp);
    }
};