class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int i=0,j=piles.size()-1,ans=0;
        while(i<j){
            i++;j--;
            ans+=piles[j];
            j--;
        }
        return ans;
    }
};