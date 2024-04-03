class Solution {
public:
    bool rec(int i, int j, int alice, int bob, bool aturn, bool bturn, vector<int> &piles,vector<vector<vector<vector<vector<vector<int>>>>>> &dp){
        if(i>j){
            return alice>bob?true:false;
        }
        if(dp[i][j][alice][bob][aturn][bturn]==-1)  return dp[i][j][alice][bob][aturn][bturn];
        int start=0,end=0;
        if(aturn){
            start=piles[i]+rec(i+1,j,alice,bob,0,1,piles,dp);
            end=piles[j]+rec(i,j-1,alice,bob,0,1,piles,dp);
            alice = max(start,end);
        }else{
            start=piles[i]+rec(i+1,j,alice,bob,0,1,piles,dp);
            end=piles[j]+rec(i,j-1,alice,bob,0,1,piles,dp);
            bob = max(start,end);
        }
        return dp[i][j][alice][bob][aturn][bturn]=alice>bob?true:false;
    }
    bool stoneGame(vector<int>& piles) {
        // vector<vector<vector<vector<vector<vector<int>>>>>> dp(piles.size(),
        //                                                       vector<vector<vector<vector<vector<int>>>>>(piles.size(),                                                                                                         vector<vector<vector<vector<int>>>>(250000,
        //                                                       vector<vector<vector<int>>> (250000,
        //                                                                                   vector<vector<int>> (2,
        //                                                                                                       vector<int>(2,-1))))));
        // return rec(0,piles.size()-1,0,0,1,0,piles,dp);
        return true;
    }
};